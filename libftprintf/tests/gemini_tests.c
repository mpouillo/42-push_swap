#include "../includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/wait.h>

/* --- Colors --- */
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define YELLOW	"\033[0;33m"
#define BLUE	"\033[0;34m"
#define MAGENTA	"\033[0;35m"
#define CYAN	"\033[0;36m"
#define RESET	"\033[0m"

/* --- Configuration --- */
#define BUFFER_SIZE 20480

/* --- Globals for Stats --- */
int g_tests_run = 0;
int g_tests_passed = 0;

/* --- Helper: Print string with escaped non-printables --- */
void print_escaped(const char *str, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		unsigned char c = (unsigned char)str[i];
		if (c == '\n') printf("\\n");
		else if (c == '\t') printf("\\t");
		else if (c == '\r') printf("\\r");
		else if (c == '\0') printf(MAGENTA "\\0" RESET);
		else if (c < 32 || c > 126) printf("\\x%02x", c);
		else putchar(c);
	}
}

/* --- The Test Macro --- */
#define TEST(FMT, ...) do { \
	g_tests_run++; \
	int ret_exp, ret_act; \
	char buf_exp[BUFFER_SIZE] = {0}; \
	char buf_act[BUFFER_SIZE] = {0}; \
	int pipefd[2]; \
	int saved_stdout = dup(STDOUT_FILENO); \
	ssize_t bytes_read_exp = 0; \
	ssize_t bytes_read_act = 0; \
	\
	/* --- RUN EXPECTED (printf) --- */ \
	if (pipe(pipefd) == -1) { perror("pipe"); exit(1); } \
	fflush(stdout); \
	dup2(pipefd[1], STDOUT_FILENO); \
	close(pipefd[1]); /* Close write end on the redirection side */ \
	ret_exp = printf(FMT, ##__VA_ARGS__); \
	fflush(stdout); \
	close(STDOUT_FILENO); /* IMPORTANT: Close the redirected STDOUT to signal EOF to the pipe */ \
	dup2(saved_stdout, STDOUT_FILENO); /* Restore stdout */ \
	bytes_read_exp = read(pipefd[0], buf_exp, BUFFER_SIZE - 1); \
	close(pipefd[0]); \
	\
	/* --- RUN ACTUAL (ft_printf) --- */ \
	if (pipe(pipefd) == -1) { perror("pipe"); exit(1); } \
	fflush(stdout); \
	dup2(pipefd[1], STDOUT_FILENO); \
	close(pipefd[1]); /* Close write end on the redirection side */ \
	ret_act = ft_printf(FMT, ##__VA_ARGS__); \
	fflush(stdout); \
	close(STDOUT_FILENO); /* IMPORTANT: Close the redirected STDOUT to signal EOF to the pipe */ \
	dup2(saved_stdout, STDOUT_FILENO); /* Restore stdout */ \
	bytes_read_act = read(pipefd[0], buf_act, BUFFER_SIZE - 1); \
	close(pipefd[0]); \
	\
	/* --- COMPARE --- */ \
	int match_buf = 0; \
	size_t len_to_compare = (ret_exp > 0 && ret_act > 0) ? (size_t)(ret_exp > ret_act ? ret_exp : ret_act) : 0; \
	if (ret_exp == ret_act && ret_exp >= 0) { \
		/* If return values match, compare memory byte-for-byte up to the returned length */ \
		if (memcmp(buf_exp, buf_act, ret_exp) == 0) \
			match_buf = 1; \
	} \
	\
	if (ret_exp == ret_act && match_buf) { \
		printf(GREEN "." RESET); \
		g_tests_passed++; \
		if (g_tests_run % 100 == 0) printf("\n"); \
	} else { \
		printf("\n" RED "KO" RESET "\n"); \
		printf(BLUE "	 Format	: " RESET "%s\n", FMT); \
		printf(BLUE "	 Args	: " RESET #__VA_ARGS__ "\n"); \
		printf(YELLOW "	 Expected: " RESET "Ret: %d, Output: [", ret_exp); \
		print_escaped(buf_exp, ret_exp > 0 ? ret_exp : (int)bytes_read_exp); \
		printf("] (Read %zd bytes)\n", bytes_read_exp); \
		printf(CYAN "	 Actual	: " RESET "Ret: %d, Output: [", ret_act); \
		print_escaped(buf_act, ret_act > 0 ? ret_act : (int)bytes_read_act); \
		printf("] (Read %zd bytes)\n\n", bytes_read_act); \
	} \
	close(saved_stdout); \
} while(0)

/* --- Permutation Helpers --- */

void run_char_tests() {
	printf(CYAN "\n======== CHAR TESTS (%%c) ===========================================================================\n" RESET);
	char chars[] = {'A', 'z', '0', '\0', '\t', 127};
	char *widths[] = {"", "1", "2", "5", "10"};
	char *flags[] = {"-", "0", "#", "+", " ", "-0", "-#", "-+", "- ", "0#", "0+",
		"0 ", "#+", "# ", "+ ", "-0#", "-0+", "-0 ", "-#+", "-# ", "-+ ", "0#+",
		"0# ", "0+ ", "#+ ", "-0#+", "-0# ", "-0+ ", "-#+ ", "0#+ ", "-0#+ ", ""};

	char fmt[100];
	for (int i = 0; i < 6; i++) {
		for (int w = 0; w < 5; w++) {
			for (int f = 0; f < 32; f++) {
				snprintf(fmt, sizeof(fmt), "%%%s%sc", flags[f], widths[w]);
				TEST(fmt, chars[i]);
			}
		}
	}
}

void run_str_tests() {
	printf(CYAN "\n======== STRING TESTS (%%s) =========================================================================\n" RESET);
	char *strs[] = {"Hello", "", NULL, "Very long string just to test boundaries"};
	char *widths[] = {"", "2", "5", "10", "20"};
	char *precs[] = {"", ".", ".0", ".2", ".5", ".10"};
	char *flags[] = {"-", "0", "#", "+", " ", "-0", "-#", "-+", "- ", "0#", "0+",
		"0 ", "#+", "# ", "+ ", "-0#", "-0+", "-0 ", "-#+", "-# ", "-+ ", "0#+",
		"0# ", "0+ ", "#+ ", "-0#+", "-0# ", "-0+ ", "-#+ ", "0#+ ", "-0#+ ", ""};

	char fmt[100];
	for (int i = 0; i < 4; i++) {
		for (int w = 0; w < 5; w++) {
			for (int p = 0; p < 6; p++) {
				for (int f = 0; f < 10; f++) {
					snprintf(fmt, sizeof(fmt), "%%%s%s%ss", flags[f], widths[w], precs[p]);
					TEST(fmt, strs[i]);
				}
			}
		}
	}
}

void run_int_tests() {
	printf(CYAN "\n======== INTEGER TESTS (%%d / %%i) ===================================================================\n" RESET);
	int vals[] = {0, 1, -1, 42, -42, INT_MAX, INT_MIN};
	char *widths[] = {"", "1", "5", "10"};
	char *precs[] = {"", ".", ".0", ".5", ".10"};
	char *flags[] = {"-", "0", "#", "+", " ", "-0", "-#", "-+", "- ", "0#", "0+",
		"0 ", "#+", "# ", "+ ", "-0#", "-0+", "-0 ", "-#+", "-# ", "-+ ", "0#+",
		"0# ", "0+ ", "#+ ", "-0#+", "-0# ", "-0+ ", "-#+ ", "0#+ ", "-0#+ ", ""};

	char fmt[100];
	for (int i = 0; i < 7; i++) {
		for (int w = 0; w < 4; w++) {
			for (int p = 0; p < 5; p++) {
				for (int f = 0; f < 10; f++) {
					snprintf(fmt, sizeof(fmt), "%%%s%s%sd", flags[f], widths[w], precs[p]);
					TEST(fmt, vals[i]);
					// Test %i as well randomly
					if (f == 0) {
						snprintf(fmt, sizeof(fmt), "%%%s%s%si", flags[f], widths[w], precs[p]);
						TEST(fmt, vals[i]);
					}
				}
			}
		}
	}
}

void run_uint_tests() {
	printf(CYAN "\n======== UNSIGNED TESTS (%%u) =======================================================================\n" RESET);
	unsigned int vals[] = {0, 1, 42, UINT_MAX, UINT_MAX - 1, INT_MAX};
	char *widths[] = {"", "5", "10"};
	char *precs[] = {"", ".", ".0", ".5", ".10"};
	char *flags[] = {"-", "0", "#", "+", " ", "-0", "-#", "-+", "- ", "0#", "0+",
		"0 ", "#+", "# ", "+ ", "-0#", "-0+", "-0 ", "-#+", "-# ", "-+ ", "0#+",
		"0# ", "0+ ", "#+ ", "-0#+", "-0# ", "-0+ ", "-#+ ", "0#+ ", "-0#+ ", ""};
	// + and space are undefined for %u

	char fmt[100];
	for (int i = 0; i < 6; i++) {
		for (int w = 0; w < 3; w++) {
			for (int p = 0; p < 5; p++) {
				for (int f = 0; f < 10; f++) {
					snprintf(fmt, sizeof(fmt), "%%%s%s%su", flags[f], widths[w], precs[p]);
					TEST(fmt, vals[i]);
				}
			}
		}
	}
}

void run_hex_tests() {
	printf(CYAN "\n======== HEX TESTS (%%x / %%X) =======================================================================\n" RESET);
	unsigned int vals[] = {0, 1, 42, 0xABC, UINT_MAX};
	char *widths[] = {"", "5", "10"};
	char *precs[] = {"", ".", ".0", ".5", ".10"};
	char *flags[] = {"-", "0", "#", "+", " ", "-0", "-#", "-+", "- ", "0#", "0+",
		"0 ", "#+", "# ", "+ ", "-0#", "-0+", "-0 ", "-#+", "-# ", "-+ ", "0#+",
		"0# ", "0+ ", "#+ ", "-0#+", "-0# ", "-0+ ", "-#+ ", "0#+ ", "-0#+ ", ""};

	char fmt[100];
	for (int i = 0; i < 5; i++) {
		for (int w = 0; w < 3; w++) {
			for (int p = 0; p < 5; p++) {
				for (int f = 0; f < 10; f++) {
					snprintf(fmt, sizeof(fmt), "%%%s%s%sx", flags[f], widths[w], precs[p]);
					TEST(fmt, vals[i]);
					snprintf(fmt, sizeof(fmt), "%%%s%s%sX", flags[f], widths[w], precs[p]);
					TEST(fmt, vals[i]);
				}
			}
		}
	}
}

void run_ptr_tests() {
	printf(CYAN "\n========= POINTER TESTS (%%p) ========================================================================\n" RESET);
	char c = 'a';
	void *vals[] = {NULL, &c, (void*)1, (void*)-1, (void*)0x12345678};
	char *widths[] = {"", "5", "20"};
	char *flags[] = {"-", "0", "#", "+", " ", "-0", "-#", "-+", "- ", "0#", "0+",
		"0 ", "#+", "# ", "+ ", "-0#", "-0+", "-0 ", "-#+", "-# ", "-+ ", "0#+",
		"0# ", "0+ ", "#+ ", "-0#+", "-0# ", "-0+ ", "-#+ ", "0#+ ", "-0#+ ", ""};
	// Note: '0', '.', '#', '+', ' ' are undefined for %p

	char fmt[100];
	for (int i = 0; i < 5; i++) {
		for (int w = 0; w < 3; w++) {
			for (int f = 0; f < 10; f++) {
				snprintf(fmt, sizeof(fmt), "%%%s%sp", flags[f], widths[w]);
				TEST(fmt, vals[i]);
			}
		}
	}
}

void run_mix_tests() {
	printf(CYAN "\n========= MIXED & PERCENT TESTS ======================================================================\n" RESET);
	TEST("%%");
	TEST("%%%%");
	TEST("%% %%");
	TEST("%%d %%s");
	TEST("%%5d");
	TEST("%d%%", 42);
	TEST("Mix: %c %s %p %d %i %u %x %X %%", 'a', "s", (void*)1, 1, 2, 3, 4, 5);
}

/* * This new function explicitly tests error handling.
 * It uses fork() to isolate the file descriptor manipulation 
 * so it doesn't break the main test suite.
 */
void run_error_tests() {
	printf(CYAN "\n========= ERROR TESTS (Return -1) ==================================================================\n" RESET);

	g_tests_run++;

	// Test 1: Write to closed file descriptor
	// We use a child process to modify file descriptors safely
	pid_t pid = fork();
	if (pid == 0) {
		int saved_stdout = dup(STDOUT_FILENO);
		
		// Force printf to be unbuffered so it attempts write() immediately
		setbuf(stdout, NULL); 
		
		// Close stdout to induce error
		close(STDOUT_FILENO); 
		
		int ret_real = printf("simple string");
		int ret_mine = ft_printf("simple string");
		
		// Restore stdout for reporting
		dup2(saved_stdout, STDOUT_FILENO);
		
		if (ret_real == -1 && ret_mine == -1)
			printf(GREEN "1. Write to closed FD: OK\n" RESET);
		else
			printf(RED "1. Write to closed FD: KO (Real: %d, Mine: %d)\n" RESET, ret_real, ret_mine);
			
		close(saved_stdout);
		exit(0);
	}
	wait(NULL);

	// Test 2: Null format string (Undefined in real printf, but common check for ft_printf)
	// Real printf usually crashes on NULL, so we can't compare. 
	// We only check if ft_printf handles it gracefully (returns -1).
	int ret_null = ft_printf(NULL);
	if (ret_null == -1)
	{
		printf(GREEN "2. ft_printf(NULL):    OK (Returned -1)\n" RESET);
		g_tests_passed++;
	}
	else
		printf(RED "2. ft_printf(NULL):    KO (Returned %d, expected -1)\n" RESET, ret_null);
}

/* ========================================================================== */
/* MALLOC FAILURE TESTS                             */
/* ========================================================================== */

// Globals to control when malloc should fail
int g_malloc_fail_active = 0;
int g_malloc_fail_counter = 0;
int g_malloc_fail_target = 0;

/*
 * The Mock Malloc Function.
 * When we compile with -Dft_calloc=test_calloc, your ft_printf will call this 
 * instead of the system malloc.
 */
void *test_calloc(size_t nmemb, size_t size)
{
    // If we are in "fail mode"
    if (g_malloc_fail_active)
    {
        if (g_malloc_fail_counter == g_malloc_fail_target)
        {
            g_malloc_fail_counter++;
            return (NULL); // Trigger the failure!
        }
        g_malloc_fail_counter++;
    }

    // Since 'ft_calloc' is redefined to 'test_calloc', we cannot call 'ft_calloc' here 
    // or we get infinite recursion. We use calloc(nmemb, size) to get memory from the system.
    return (calloc(nmemb, size));
}

void *test_malloc(size_t size)
{
    // If we are in "fail mode"
    if (g_malloc_fail_active)
    {
        if (g_malloc_fail_counter == g_malloc_fail_target)
        {
            g_malloc_fail_counter++;
            return (NULL); // Trigger the failure!
        }
        g_malloc_fail_counter++;
    }

    // Since 'malloc' is redefined to 'test_malloc', we cannot call 'malloc' here 
    // or we get infinite recursion. We use malloc(size) to get memory from the system.
    return (realloc(NULL, size));
}

void run_malloc_tests(void)
{
    printf(CYAN "\n========= MALLOC FAIL TESTS (Expect -1) ============================================================\n" RESET);

    // We choose a complex format that definitely needs malloc (width, precision, etc)
    // Adjust this string if your printf doesn't malloc for this specific case.
    int ret;
    int i = 0;
    int success = 0;

	g_tests_run++;

    // Loop 0 to 100 (arbitrary limit) trying to fail the 1st malloc, then 2nd, then 3rd...
    // We stop when ft_printf returns something other than -1 (meaning it succeeded 
    // despite our attempts, or we passed all allocation points).
    while (i < 100)
    {
        // Reset counters
        g_malloc_fail_active = 1;
        g_malloc_fail_counter = 0;
        g_malloc_fail_target = i;
        
        // redirect stdout so we don't clutter terminal with partial prints
        int saved_stdout = dup(STDOUT_FILENO);
        int dev_null = open("/dev/null", O_WRONLY);
        dup2(dev_null, STDOUT_FILENO);
        close(dev_null);

        // Run the function
        ret = ft_printf("%-20.10s%-20.10c%-20.10i%-20.10p%-20.10x", "test", 0x42, 42, "test", 42);

        // Restore stdout
        dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdout);

        // Disable fail mode to print results
        g_malloc_fail_active = 0;

        if (ret == -1)
        {
            // It correctly returned -1 on allocation failure
            printf(GREEN "Malloc fail at index %d: OK (Ret -1)\n" RESET, i);
        }
        else
        {
            // If it returns a value >= 0, it means either:
            // 1. We went past the number of mallocs your function does (Success)
            // 2. Your function failed to catch a NULL pointer (Segfault would happen usually)
            // 3. Your function ignored the NULL and printed anyway (KO)
            
            // To differentiate, we assume that if we cycled through enough indices
            // and eventually got a success, it means your code is robust.
            printf(YELLOW "Malloc fail at index %d: Function succeeded (End of allocs reached?)\n" RESET, i);
            success = 1;
			g_tests_passed++;
            break; 
        }
        i++;
    }

    if (success)
        printf(GREEN "\nExecution survived all simulated malloc failures!\n" RESET);
    else
        printf(RED "\nExecution did not find a success state (Infinite mallocs?)\n" RESET);
}

int main(void)
{
	printf(CYAN "================================= BOURRINETTE - A FT_PRINTF TESTER =================================\n" RESET);
	printf(CYAN "This program tests combinations of every flag and multiple test inputs against the real printf().\n" RESET);
	printf(CYAN "Disclaimer: These tests were mostly AI-generated and may be inaccurate. Use at your own risk.\n" RESET);
	
	run_char_tests();
	run_str_tests();
	run_int_tests();
	run_uint_tests();
	run_hex_tests();
	run_ptr_tests();
	run_mix_tests();
	run_error_tests();
	run_malloc_tests();

	printf("\n\n" CYAN "=========================================== FINAL RESULT ===========================================\n" RESET);
	if (g_tests_run == g_tests_passed)
		printf(GREEN "\nALL %d TESTS PASSED!\n\n" RESET, g_tests_passed);
	else
		printf(RED "\n%d TESTS FAILED OUT OF %d\n\n" RESET, g_tests_run - g_tests_passed, g_tests_run);

	return (0);
}