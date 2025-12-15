#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	/*
	char c = 0x41;
	char *s = "Hello World!";
	int i = -42;
	unsigned int u = 42;
	int x = 0xFF;
	ft_printf("Printing: < %s >\n", "ft_printf(\"c: \%c\\ns: \%s\\np: \%p\\nd: \%d\\ni: \%i\\nu: \%u\\nx: \%x\\nX: \%X\\n\%\%: \%\%\\n\", c, s, s, i, i, u, x, x)");
	ft_printf("c: %c\ns: %s\np: %p\nd: %d\ni: %i\n\nu: %u\nx: %x\nX: %X\n%%: %%\n", c, s, s, i, i, u, x, x);
	*/

	int a = 0;
	int b = 0;
	int x = UINT_MAX;
	char c = 'A';    // Standard character
	char z = 0;      // Null character (ASCII 0)
	char *s = "Hello World!";
	char *empty = "";
	char *null_str = NULL;
	int w = 20;
	int p = 10;
	int pos = 42;
	int neg = -42;
	int zero = 0;
	int long_num = 123456789;
	int int_max = INT_MAX;       // 2147483647
	int int_min = INT_MIN;       // -2147483648
	long long big_pos = 2147483648LL; // Value just > INT_MAX
	long long big_neg = -2147483649LL; // Value just < INT_MIN
	unsigned int u_val = 4294967200U; // A large unsigned value
	unsigned int u_pos = 12345;
	unsigned int u_zero = 0;
	unsigned int u_max = UINT_MAX; // 4294967295 (on most systems)
	int i_neg = -1;
	// Assume 'a' and 'b' are defined for return values.
	unsigned int u_val_small = 43;      // 2b in hex
	unsigned int u_val_medium = 34;     // 22 in hex
	unsigned int u_val_large = 0xFFFF;  // ffff in hex
	unsigned int hex_val = 2748;   // Hex: abc

	printf("\n\033[1;34m=== FT_PRINTF TESTS ===\n");


	printf("\n\n\033[1;34m=== CHARACTER (%%c) ===\n\n");

	printf("\033[1;34m--- A. Basic Width and Justification Tests ---\n\n");

	printf("\033[1;34m1. Basic char (No modifiers)\n");
	a = printf("\033[1;33m'%%c'        |%c|\n", c);
	b = ft_printf("\033[1;36m'%%c'        |%c|\n", c);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m2. Width only (Right-justified)\n");
	a = printf("\033[1;33m'%%10c'      |%10c|\n", c);
	b = ft_printf("\033[1;36m'%%10c'      |%10c|\n", c);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m3. Width of 1 (No padding)\n");
	a = printf("\033[1;33m'%%1c'       |%1c|\n", c);
	b = ft_printf("\033[1;36m'%%1c'       |%1c|\n", c);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m4. Left-justified, width\n");
	a = printf("\033[1;33m'%%-10c'     |%-10c|\n", c);
	b = ft_printf("\033[1;36m'%%-10c'     |%-10c|\n", c);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\n\033[1;34m--- B. Precision and 0-Flag (Should be Ignored) ---\n\n");

	printf("\033[1;34m5. Precision only (Must be Ignored)\n");
	a = printf("\033[1;33m'%%.5c'      |%.5c|\n", c);
	b = ft_printf("\033[1;36m'%%.5c'      |%.5c|\n", c);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m6. Width and Precision (Precision Ignored)\n");
	a = printf("\033[1;33m'%%10.5c'    |%10.5c|\n", c);
	b = ft_printf("\033[1;36m'%%10.5c'    |%10.5c|\n", c);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m7. Left-justified and Precision (Precision Ignored)\n");
	a = printf("\033[1;33m'%%-10.5c'   |%-10.5c|\n", c);
	b = ft_printf("\033[1;36m'%%-10.5c'   |%-10.5c|\n", c);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m8. 0 Flag (Must be Ignored, defaults to space padding)\n");
	a = printf("\033[1;33m'%%010c'     |%010c|\n", c);
	b = ft_printf("\033[1;36m'%%010c'     |%010c|\n", c);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m9. 0 Flag with Left-Justification (Both Ignored for padding)\n");
	a = printf("\033[1;33m'%%-010c'    |%-010c|\n", c);
	b = ft_printf("\033[1;36m'%%-010c'    |%-010c|\n", c);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\n\033[1;34m--- C. Null Character ('\0') Edge Cases ---\n\n");

	printf("\033[1;34m10. Null character (Should print NUL, Length 1)\n");
	a = printf("\033[1;33m'%%c'        |%c|\n", z);
	b = ft_printf("\033[1;36m'%%c'        |%c|\n", z);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m11. Null character, with width\n");
	a = printf("\033[1;33m'%%10c'      |%10c|\n", z);
	b = ft_printf("\033[1;36m'%%10c'      |%10c|\n", z);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m12. Null character, left-justified\n");
	a = printf("\033[1;33m'%%-10c'     |%-10c|\n", z);
	b = ft_printf("\033[1;36m'%%-10c'     |%-10c|\n", z);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\n\033[1;34m--- D. Star-based width/precision Tests ---\n\n");

	printf("\033[1;34m13. Star width\n");
	a = printf("\033[1;33m'%%*c'       |%*c|\n", w, c);
	b = ft_printf("\033[1;36m'%%*c'       |%*c|\n", w, c);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m14. Star precision (Must be Ignored)\n");
	a = printf("\033[1;33m'%%.*c'      |%.*c|\n", p, c);
	b = ft_printf("\033[1;36m'%%.*c'      |%.*c|\n", p, c);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m15. Star width and star precision, left-justified (Precision Ignored)\n");
	a = printf("\033[1;33m'%%-*.*c'    |%-*.*c|\n", w, p, c);
	b = ft_printf("\033[1;36m'%%-*.*c'    |%-*.*c|\n", w, p, c);
	printf("\033[1;35m%i / %i\n\n", a, b);


	printf("\033[1;34mEXTRA TESTS: PACO EDITION 1\n");
	a = printf("\033[1;33m        | %c %c %c|\n", '0', 0, '1');
	b = ft_printf("\033[1;36m        | %c %c %c|\n", '0', 0, '1');
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION 2\n");
	a = printf("\033[1;33m        | %c %c %c|\n", '2', '1', 0);
	b = ft_printf("\033[1;36m        | %c %c %c|\n", '2', '1', 0);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION 3\n");
	a = printf("\033[1;33m        | %c %c %c|\n", 0, '1', '2');
	b = ft_printf("\033[1;36m        | %c %c %c|\n", 0, '1', '2');
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\n\033[1;34m=== STRING ===\n\n");

	printf("\033[1;34m--- A. Basic Width and Precision Tests ---\n\n");

	printf("\033[1;34m1. Basic string (No modifiers)\n");
	a = printf("\033[1;33m'%%s'       |%s|\n", s);
	b = ft_printf("\033[1;36m'%%s'       |%s|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m2. Width only (Right-justified)\n");
	a = printf("\033[1;33m'%%20s'     |%20s|\n", s);
	b = ft_printf("\033[1;36m'%%20s'     |%20s|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m3. Precision only (Truncation)\n");
	a = printf("\033[1;33m'%%.5s'      |%.5s|\n", s);
	b = ft_printf("\033[1;36m'%%.5s'      |%.5s|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m4. Width smaller than string (Width ignored)\n");
	a = printf("\033[1;33m'%%5s'      |%5s|\n", s);
	b = ft_printf("\033[1;36m'%%5s'      |%5s|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m5. Precision of zero (Truncation to empty)\n");
	a = printf("\033[1;33m'%%.0s'      |%.0s|\n", s);
	b = ft_printf("\033[1;36m'%%.0s'      |%.0s|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- B. Left-Justification Combinations (Flag '-') ---\n\n");

	printf("\033[1;34m6. Left-justified, no precision\n");
	a = printf("\033[1;33m'%%-20s'    |%-20s|\n", s);
	b = ft_printf("\033[1;36m'%%-20s'    |%-20s|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m7. Left-justified, with truncation (Precision < String Length < Width)\n");
	a = printf("\033[1;33m'%%-20.5s'  |%-20.5s|\n", s);
	b = ft_printf("\033[1;36m'%%-20.5s'  |%-20.5s|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m8. Left-justified, width smaller than truncated string\n");
	a = printf("\033[1;33m'%%-5.10s'  |%-5.10s|\n", s);
	b = ft_printf("\033[1;36m'%%-5.10s'  |%-5.10s|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m9. Left-justified, zero precision\n");
	a = printf("\033[1;33m'%%-10.0s'  |%-10.0s|\n", s);
	b = ft_printf("\033[1;36m'%%-10.0s'  |%-10.0s|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- C. Edge Cases (Empty and NULL Strings) ---\n\n");

	printf("\033[1;34m10. Empty string, width only\n");
	a = printf("\033[1;33m'%%10s'     |%10s|\n", empty);
	b = ft_printf("\033[1;36m'%%10s'     |%10s|\n", empty);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m11. Empty string, left-justified\n");
	a = printf("\033[1;33m'%%-10s'    |%-10s|\n", empty);
	b = ft_printf("\033[1;36m'%%-10s'    |%-10s|\n", empty);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m12. NULL string (Standard requires printing '(null)')\n");
	a = printf("\033[1;33m'%%s'       |%s|\n", null_str);
	b = ft_printf("\033[1;36m'%%s'       |%s|\n", null_str);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m13. NULL string, with width\n");
	a = printf("\033[1;33m'%%10s'     |%10s|\n", null_str);
	b = ft_printf("\033[1;36m'%%10s'     |%10s|\n", null_str);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m14. NULL string, with left-justification\n");
	a = printf("\033[1;33m'%%-10s'    |%-10s|\n", null_str);
	b = ft_printf("\033[1;36m'%%-10s'    |%-10s|\n", null_str);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m15. NULL string, with precision (crucial test: precision truncates '(null)')\n");
	a = printf("\033[1;33m'%%.2s'      |%.2s|\n", null_str);
	b = ft_printf("\033[1;36m'%%.2s'      |%.2s|\n", null_str);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m16. NULL string, with width and truncating precision\n");
	a = printf("\033[1;33m'%%10.2s'   |%10.2s|\n", null_str);
	b = ft_printf("\033[1;36m'%%10.2s'   |%10.2s|\n", null_str);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m17. NULL string, with left-justification and truncating precision\n");
	a = printf("\033[1;33m'%%-10.2s'  |%-10.2s|\n", null_str);
	b = ft_printf("\033[1;36m'%%-10.2s'  |%-10.2s|\n", null_str);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- D. Star-based width/precision Tests ---\n\n");

	printf("\033[1;34m18. Star width\n");
	a = printf("\033[1;33m'%%*s'      |%*s|\n", w, s);
	b = ft_printf("\033[1;36m'%%*s'      |%*s|\n", w, s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m19. Star precision\n");
	a = printf("\033[1;33m'%%.*s'     |%.*s|\n", p, s);
	b = ft_printf("\033[1;36m'%%.*s'     |%.*s|\n", p, s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m20. Star width and star precision, left-justified\n");
	a = printf("\033[1;33m'%%-*.*s'   |%-*.*s|\n", w, p, s);
	b = ft_printf("\033[1;36m'%%-*.*s'   |%-*.*s|\n", w, p, s);
	printf("\033[1;35m%i / %i\n\n", a, b);



	printf("\n\033[1;34m=== POINTER (%%p) ===\n\n");

	printf("\033[1;34m--- A. Basic Pointer Tests (Non-NULL) ---\n\n");

	printf("\033[1;34m1. Basic pointer (No modifiers)\n");
	a = printf("\033[1;33m'%%p'        |%p|\n", s);
	b = ft_printf("\033[1;36m'%%p'        |%p|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m1.5. Basic pointer (- modifier)\n");
	a = printf("\033[1;33m'%%-p'        |%-p|\n", s);
	b = ft_printf("\033[1;36m'%%p'        |%-p|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m2. Width only (Right-justified)\n");
	a = printf("\033[1;33m'%%20p'      |%20p|\n", s);
	b = ft_printf("\033[1;36m'%%20p'      |%20p|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m3. Width smaller than pointer length (Width ignored)\n");
	a = printf("\033[1;33m'%%5p'       |%5p|\n", s);
	b = ft_printf("\033[1;36m'%%5p'       |%5p|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m4. Left-justified, width\n");
	a = printf("\033[1;33m'%%-20p'     |%-20p|\n", s);
	b = ft_printf("\033[1;36m'%%-20p'     |%-20p|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- B. Null Pointer Edge Cases ---\n\n");

	printf("\033[1;34m5. NULL pointer (Should print '(nil)' or similar, length dependent)\n");
	a = printf("\033[1;33m'%%p'        |%p|\n", null_str);
	b = ft_printf("\033[1;36m'%%p'        |%p|\n", null_str);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m5.5. NULL pointer (with -)\n");
	a = printf("\033[1;33m'%%-p'       |%-p|\n", null_str);
	b = ft_printf("\033[1;36m'%%-p'       |%-p|\n", null_str);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m6. NULL pointer, with width (Right-justified)\n");
	a = printf("\033[1;33m'%%10p'      |%10p|\n", null_str);
	b = ft_printf("\033[1;36m'%%10p'      |%10p|\n", null_str);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m7. NULL pointer, left-justified\n");
	a = printf("\033[1;33m'%%-10p'     |%-10p|\n", null_str);
	b = ft_printf("\033[1;36m'%%-10p'     |%-10p|\n", null_str);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- C. Unsupported/Ignored Flags (Must not change output) ---\n\n");

	// Note: Precision, 0, #, +, and space flags are ignored or UB for %p. 
	// We test width with these to ensure they don't corrupt the padding.

	printf("\033[1;34m8. Precision (Must be Ignored)\n");
	a = printf("\033[1;33m'%%.10p'     |%.10p|\n", s);
	b = ft_printf("\033[1;36m'%%.10p'     |%.10p|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m9. 0 Flag (Must be Ignored, use space padding)\n");
	a = printf("\033[1;33m'%%020p'     |%020p|\n", s);
	b = ft_printf("\033[1;36m'%%020p'     |%020p|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m10. Left-justified and 0 Flag (0 Ignored)\n");
	a = printf("\033[1;33m'%%-020p'    |%-020p|\n", s);
	b = ft_printf("\033[1;36m'%%-020p'    |%-020p|\n", s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- D. Star-based width Tests ---\n\n");

	printf("\033[1;34m11. Star width\n");
	a = printf("\033[1;33m'%%*p'       |%*p|\n", w, s);
	b = ft_printf("\033[1;36m'%%*p'       |%*p|\n", w, s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m12. Star width, left-justified\n");
	a = printf("\033[1;33m'%%-*p'      |%-*p|\n", w, s);
	b = ft_printf("\033[1;36m'%%-*p'      |%-*p|\n", w, s);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION 1\n");
	a = printf("\033[1;33m -1         |%p|\n", -1);
	b = ft_printf("\033[1;36m -1         |%p|\n", -1);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION 2\n");
	a = printf("\033[1;33m 1          |%p|\n", 1);
	b = ft_printf("\033[1;36m 1          |%p|\n", 1);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION 3\n");
	a = printf("\033[1;33m 15         |%p|\n", 15);
	b = ft_printf("\033[1;36m 15         |%p|\n", 15);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION 4\n");
	a = printf("\033[1;33m LONG_MIN / LONG_MAX          |%p %p|\n", LONG_MIN, LONG_MAX);
	b = ft_printf("\033[1;36m LONG_MIN / LONG_MAX          |%p %p|\n", LONG_MIN, LONG_MAX);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION 5\n");
	a = printf("\033[1;33m INT_MIN / INT_MAX            |%p %p|\n", INT_MIN, INT_MAX);
	b = ft_printf("\033[1;36m INT_MIN / INT_MAX            |%p %p|\n", INT_MIN, INT_MAX);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION 6\n");
	a = printf("\033[1;33m ULONG_MAX / -ULONG_MAX       |%p %p|\n", ULONG_MAX, -ULONG_MAX);
	b = ft_printf("\033[1;36m ULONG_MAX / -ULONG_MAX       |%p %p|\n", ULONG_MAX, -ULONG_MAX);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION 7\n");
	a = printf("\033[1;33m ULONG_MAX / -ULONG_MAX       |%p %p|\n", 0, 0);
	b = ft_printf("\033[1;36m ULONG_MAX / -ULONG_MAX       |%p %p|\n", 0, 0);
	printf("\033[1;35m%i / %i\n\n", a, b);


	printf("\n\033[1;34m=== HEX ===\n\n");

	a = printf("\033[1;33m'%10x'\n", x);
	b = ft_printf("\033[1;36m'%10x'\n", x);
	printf("\033[1;35m%i / %i\n\n\n", a, b);

	a = printf("\033[1;33m'%-10x'\n", x);
	b = ft_printf("\033[1;36m'%-10x'\n", x);
	printf("\033[1;35m%i / %i\n\n", a, b);

	a = printf("\033[1;33m'%10X'\n", x);
	b = ft_printf("\033[1;36m'%10X'\n", x);
	printf("\033[1;35m%i / %i\n\n\n", a, b);

	a = printf("\033[1;33m'%-10X'\n", x);
	b = ft_printf("\033[1;36m'%-10X'\n", x);
	printf("\033[1;35m%i / %i\n\n", a, b);

	a = printf("\033[1;33m'%10X'\n", 0x1);
	b = ft_printf("\033[1;36m'%10X'\n", 0x1);
	printf("\033[1;35m%i / %i\n\n\n", a, b);

	a = printf("\033[1;33m'%-10X'\n", 0x1);
	b = ft_printf("\033[1;36m'%-10X'\n", 0x1);
	printf("\033[1;35m%i / %i\n\n", a, b);

	a = printf("\033[1;33m'%10.6x'\n", 0x1);
	b = ft_printf("\033[1;36m'%10.6x'\n", 0x1);
	printf("\033[1;35m%i / %i\n\n\n", a, b);

	a = printf("\033[1;33m'%10.6x'\n", 0x0);
	b = ft_printf("\033[1;36m'%10.6x'\n", 0x0);
	printf("\033[1;35m%i / %i\n\n\n", a, b);

	a = printf("\033[1;33m'%*.*x'\n", 10, 6, 0x1);
	b = ft_printf("\033[1;36m'%*.*x'\n", 10, 6, 0x1);
	printf("\033[1;35m%i / %i\n\n\n", a, b);

	a = printf("\033[1;33m'%*.*x'\n", 10, 6, 0x0);
	b = ft_printf("\033[1;36m'%*.*x'\n", 10, 6, 0x0);
	printf("\033[1;35m%i / %i\n\n\n", a, b);

	a = printf("\033[1;33m'%x'\n", 16);
	b = ft_printf("\033[1;36m'%x'\n", 16);
	printf("\033[1;35m%i / %i\n\n\n", a, b);

	printf("\n\033[1;34m=== HEXADECIMAL (%%x, %%X) ===\n\n");

	printf("\033[1;34m--- A. Basic Width and Precision Tests ---\n\n");

	printf("\033[1;34m1. Basic lowercase hex (No modifiers)\n");
	// Expected: "abc"
	a = printf("\033[1;33m'%%x'        |%x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%x'        |%x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m2. Basic uppercase hex (No modifiers)\n");
	// Expected: "ABC"
	a = printf("\033[1;33m'%%X'        |%X|\n", hex_val);
	b = ft_printf("\033[1;36m'%%X'        |%X|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m3. Max unsigned int\n");
	a = printf("\033[1;33m'%%x'        |%x|\n", u_max);
	b = ft_printf("\033[1;36m'%%x'        |%x|\n", u_max);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m4. Width only (Right-justified)\n");
	// Expected: "          abc"
	a = printf("\033[1;33m'%%13x'      |%13x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%13x'      |%13x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m5. Precision only (Forces minimum digits)\n");
	// Expected: "00000abc" (8 digits)
	a = printf("\033[1;33m'%%.8x'      |%.8x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%.8x'      |%.8x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- B. Ignored Flags ('+', ' ') ---\n\n");

	printf("\033[1;34m6. Plus flag ('+') (Must be ignored)\n");
	a = printf("\033[1;33m'%%+x'       |%+x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%+x'       |%+x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m7. Space flag (' ') (Must be ignored)\n");
	a = printf("\033[1;33m'%% x'        |% x|\n", hex_val);
	b = ft_printf("\033[1;36m'%% x'        |% x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- C. Alternate Form ('#') ---\n\n");

	printf("\033[1;34m8. Alternate form, lowercase\n");
	// Expected: "0xabc"
	a = printf("\033[1;33m'%%#x'       |%#x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%#x'       |%#x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m9. Alternate form, uppercase\n");
	// Expected: "0XABC"
	a = printf("\033[1;33m'%%#X'       |%#X|\n", hex_val);
	b = ft_printf("\033[1;36m'%%#X'       |%#X|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m10. Alternate form on zero (Crucial: '#' is ignored)\n");
	// Expected: "0"
	a = printf("\033[1;33m'%%#x'       |%#x|\n", u_zero);
	b = ft_printf("\033[1;36m'%%#x'       |%#x|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- D. Zero-Padding ('0') and Justification ('-') ---\n\n");

	printf("\033[1;34m11. Zero-padding only\n");
	// Expected: "0000000000abc" (13 chars total)
	a = printf("\033[1;33m'%%013x'     |%013x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%013x'     |%013x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m12. Left-justified ('-')\n");
	// Expected: "abc          "
	a = printf("\033[1;33m'%%-13x'     |%-13x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%-13x'     |%-13x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m13. Left-justified with Zero-padding (Crucial: '-' overrides '0')\n");
	// Expected: "abc          "
	a = printf("\033[1;33m'%%-013x'    |%-013x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%-013x'    |%-013x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- E. Flag Interactions with Alternate Form ('#') ---\n\n");

	printf("\033[1;34m14. Alternate form with Zero-padding (Crucial: 0x first, then zeros)\n");
	// Expected: "0x0000000abc" (13 chars total)
	a = printf("\033[1;33m'%%#013x'    |%#013x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%#013x'    |%#013x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m15. Alternate form with Left-justification\n");
	// Expected: "0xabc        "
	a = printf("\033[1;33m'%%#-13x'    |%-#13x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%#-13x'    |%-#13x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m16. Alternate form, Zero-padding, and Uppercase (0X first, then zeros)\n");
	// Expected: "0X0000000ABC"
	a = printf("\033[1;33m'%%#013X'    |%#013X|\n", hex_val);
	b = ft_printf("\033[1;36m'%%#013X'    |%#013X|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- F. Precision Overrides Zero-Padding ---\n\n");

	printf("\033[1;34m17. Zero-padding with Precision (Crucial: '0' ignored, space padding used)\n");
	// Expected: "     00000abc" (Space padding + Precision zeros + Value)
	a = printf("\033[1;33m'%%013.10x'  |%013.10x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%013.10x'  |%013.10x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m18. Alternate form, Zero-padding, and Precision (0x prefix is NOT padded by spaces)\n");
	// Expected: " 0x0000000abc" (Space padding + 0x prefix + Precision zeros + Value)
	// Total length of "0x" + "0000000abc" is 12. Need 1 space for width 13.
	a = printf("\033[1;33m'%%#013.10x' |%#013.10x|\n", hex_val);
	b = ft_printf("\033[1;36m'%%#013.10x' |%#013.10x|\n", hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- G. Zero Value and Precision Edge Cases ---\n\n");

	printf("\033[1;34m19. Zero with precision zero (Crucial: Prints nothing)\n");
	// Expected: ""
	a = printf("\033[1;33m'%%.0x'      |%.0x|\n", u_zero);
	b = ft_printf("\033[1;36m'%%.0x'      |%.0x|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m20. Zero with precision zero and width\n");
	// Expected: "          " (10 spaces)
	a = printf("\033[1;33m'%%10.0x'    |%10.0x|\n", u_zero);
	b = ft_printf("\033[1;36m'%%10.0x'    |%10.0x|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m21. Zero with Alt form and precision zero (Crucial: '#' ignored, prints nothing)\n");
	// Expected: ""
	a = printf("\033[1;33m'%%#.0x'     |%#.0x|\n", u_zero);
	b = ft_printf("\033[1;36m'%%#.0x'     |%#.0x|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m22. Zero with Alt form, width, and precision zero\n");
	// Expected: "          " (10 spaces)
	a = printf("\033[1;33m'%%#10.0x'   |%#10.0x|\n", u_zero);
	b = ft_printf("\033[1;36m'%%#10.0x'   |%#10.0x|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- H. Star-based Width/Precision Tests ---\n\n");

	printf("\033[1;34m23. Star width with Alt form\n");
	a = printf("\033[1;33m'%%#*x'      |%#*x|\n", w, hex_val);
	b = ft_printf("\033[1;36m'%%#*x'      |%#*x|\n", w, hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m24. Star precision with Zero flag (0 ignored)\n");
	a = printf("\033[1;33m'%%0.*x'     |%0.*x|\n", p, hex_val);
	b = ft_printf("\033[1;36m'%%0.*x'     |%0.*x|\n", p, hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m25. Star width and star precision, Alt form, Left-justified\n");
	a = printf("\033[1;33m'%%#-*.*x'   |%#-*.*x|\n", w, p, hex_val);
	b = ft_printf("\033[1;36m'%%#-*.*x'   |%#-*.*x|\n", w, p, hex_val);
	printf("\033[1;35m%i / %i\n\n", a, b);



	printf("\n\033[1;34m=== INTEGER (%%d/%%i) ===\n\n");

	printf("\033[1;34m--- A. Basic Width and Precision Tests ---\n\n");

	printf("\033[1;34m1. Basic integer (No modifiers)\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", pos);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m1.5 Zero\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", zero);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m2. Width only (Right-justified, positive)\n");
	a = printf("\033[1;33m'%%10d'      |%10d|\n", pos);
	b = ft_printf("\033[1;36m'%%10d'      |%10d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m3. Precision only (Forces minimum digits, positive)\n");
	a = printf("\033[1;33m'%%.5d'      |%.5d|\n", pos);
	b = ft_printf("\033[1;36m'%%.5d'      |%.5d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m4. Width smaller than number (Width ignored)\n");
	a = printf("\033[1;33m'%%2d'       |%2d|\n", long_num);
	b = ft_printf("\033[1;36m'%%2d'       |%2d|\n", long_num);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m5. Precision of zero, non-zero number\n");
	a = printf("\033[1;33m'%%.0d'      |%.0d|\n", pos);
	b = ft_printf("\033[1;36m'%%.0d'      |%.0d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m6. Precision of zero, on zero value (Crucial test: prints empty string)\n");
	a = printf("\033[1;33m'%%.0d'      |%.0d|\n", zero);
	b = ft_printf("\033[1;36m'%%.0d'      |%.0d|\n", zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- B. Sign Flags ('+' and ' ') ---\n\n");

	printf("\033[1;34m7. Explicit positive sign ('+')\n");
	a = printf("\033[1;33m'%%+d'       |%+d|\n", pos);
	b = ft_printf("\033[1;36m'%%+d'       |%+d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m8. Space for positive sign (' ')\n");
	a = printf("\033[1;33m'%% d'        |% d|\n", pos);
	b = ft_printf("\033[1;36m'%% d'        |% d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m9. Space flag on negative number (Ignored)\n");
	a = printf("\033[1;33m'%% d'        |% d|\n", neg);
	b = ft_printf("\033[1;36m'%% d'        |% d|\n", neg);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m10. '+' and ' ' combined (Crucial: '+' overrides ' ')\n");
	a = printf("\033[1;33m'%%+ d'       |%+ d|\n", pos);
	b = ft_printf("\033[1;36m'%%+ d'       |%+ d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- C. Zero-Padding ('0') ---\n\n");

	printf("\033[1;34m11. Zero-padding (Positive)\n");
	a = printf("\033[1;33m'%%010d'     |%010d|\n", pos);
	b = ft_printf("\033[1;36m'%%010d'     |%010d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m12. Zero-padding (Negative: sign before zeros)\n");
	a = printf("\033[1;33m'%%010d'     |%010d|\n", neg);
	b = ft_printf("\033[1;36m'%%010d'     |%010d|\n", neg);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m13. Zero-padding with Precision (Crucial: '0' ignored)\n");
	a = printf("\033[1;33m'%%010.5d'   |%010.5d|\n", pos);
	b = ft_printf("\033[1;36m'%%010.5d'   |%010.5d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m14. Zero-padding with Space (' ')\n");
	a = printf("\033[1;33m'%% 010d'    |% 010d|\n", pos);
	b = ft_printf("\033[1;36m'%% 010d'    |% 010d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- D. Left-Justification Combinations (Flag '-') ---\n\n");

	printf("\033[1;34m15. Left-justified, basic\n");
	a = printf("\033[1;33m'%%-10d'     |%-10d|\n", pos);
	b = ft_printf("\033[1;36m'%%-10d'     |%-10d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m16. Left-justified and Precision\n");
	a = printf("\033[1;33m'%%-10.5d'   |%-10.5d|\n", pos);
	b = ft_printf("\033[1;36m'%%-10.5d'   |%-10.5d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m17. Left-justified, Zero-padding (Crucial: '-' ignores '0')\n");
	a = printf("\033[1;33m'%%-010d'    |%-010d|\n", pos);
	b = ft_printf("\033[1;36m'%%-010d'    |%-010d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m18. Left-justified with '+' flag\n");
	a = printf("\033[1;33m'%%-+10d'    |%-+10d|\n", pos);
	b = ft_printf("\033[1;36m'%%-+10d'    |%-+10d|\n", pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- E. Star-based Width/Precision Tests ---\n\n");

	printf("\033[1;34m19. Star width\n");
	a = printf("\033[1;33m'%%*d'       |%*d|\n", w, pos);
	b = ft_printf("\033[1;36m'%%*d'       |%*d|\n", w, pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m20. Star precision\n");
	a = printf("\033[1;33m'%%.*d'      |%.*d|\n", p, pos);
	b = ft_printf("\033[1;36m'%%.*d'      |%.*d|\n", p, pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m21. Star width and star precision, with sign and zero-padding\n");
	a = printf("\033[1;33m'%%+0*.*d'   |%+0*.*d|\n", w, p, pos);
	b = ft_printf("\033[1;36m'%%+0*.*d'   |%+0*.*d|\n", w, p, pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m22. Negative star width (Crucial: acts as '-' flag)\n");
	a = printf("\033[1;33m'%%*d' (w=-10) |%*d|\n", -10, pos);
	b = ft_printf("\033[1;36m'%%*d' (w=-10) |%*d|\n", -10, pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m23. Negative star precision (Crucial: acts as 'no precision')\n");
	a = printf("\033[1;33m'%%.*d' (p=-5) |%.*d|\n", -5, pos);
	b = ft_printf("\033[1;36m'%%.*d' (p=-5) |%.*d|\n", -5, pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- F. Type Limits and Overflow Cases ---\n\n");

	printf("\033[1;34m24. Maximum int value (INT_MAX)\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", int_max);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", int_max);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m25. Minimum int value (INT_MIN)\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", int_min);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", int_min);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m26. INT_MAX with left-justification\n");
	a = printf("\033[1;33m'%%-20d'     |%-20d|\n", int_max);
	b = ft_printf("\033[1;36m'%%-20d'     |%-20d|\n", int_max);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m27. INT_MIN with zero-padding\n");
	a = printf("\033[1;33m'%%020d'     |%020d|\n", int_min);
	b = ft_printf("\033[1;36m'%%020d'     |%020d|\n", int_min);
	printf("\033[1;35m%i / %i\n\n", a, b);

	// Undefined Behavior tests (Using long long for values outside int range)
	printf("\033[1;34m28. Value > INT_MAX (Testing potential overflow/wrap)\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", (int)big_pos);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", (int)big_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m29. Value < INT_MIN (Testing potential overflow/wrap)\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", (int)big_neg);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", (int)big_neg);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- G. Zero Value and Precision Edge Cases ---\n\n");

	printf("\033[1;34m30. Zero with precision zero (Crucial: Prints nothing)\n");
	a = printf("\033[1;33m'%%.0d'      |%.0d|\n", zero);
	b = ft_printf("\033[1;36m'%%.0d'      |%.0d|\n", zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m31. Zero with precision zero and width\n");
	a = printf("\033[1;33m'%%10.0d'    |%10.0d|\n", zero);
	b = ft_printf("\033[1;36m'%%10.0d'    |%10.0d|\n", zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m32. Zero with precision zero and left-justified width\n");
	a = printf("\033[1;33m'%%-10.0d'   |%-10.0d|\n", zero);
	b = ft_printf("\033[1;36m'%%-10.0d'   |%-10.0d|\n", zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m33. Zero with precision zero and ' ' flag (Crucial: Prints one space due to flag, then width padding)\n");
	a = printf("\033[1;33m'%% 10.0d'   |% 10.0d|\n", zero);
	b = ft_printf("\033[1;36m'%% 10.0d'   |% 10.0d|\n", zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m34. Zero with zero-padding and precision (Crucial: '0' ignored)\n");
	a = printf("\033[1;33m'%%010.5d'   |%010.5d|\n", zero);
	b = ft_printf("\033[1;36m'%%010.5d'   |%010.5d|\n", zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- H. Negative Star Field/Precision Edge Cases ---\n\n");

	printf("\033[1;34m35. Negative Star Width with Zero Padding ('0' should be ignored)\n");
	a = printf("\033[1;33m'%%0*d' (w=-10) |%0*d|\n", -10, pos);
	b = ft_printf("\033[1;36m'%%0*d' (w=-10) |%0*d|\n", -10, pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m36. Negative Star Width with '+' Flag\n");
	a = printf("\033[1;33m'%%+*d' (w=-10) |%*d|\n", -10, pos);
	b = ft_printf("\033[1;36m'%%+*d' (w=-10) |%*d|\n", -10, pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m37. Negative Star Precision with Zero Padding ('0' applied)\n");
	// Crucial: Negative precision means no precision is applied. Since there is no precision, the '0' flag takes effect.
	a = printf("\033[1;33m'%%010.*d' (p=-5) |%010.*d|\n", -5, pos);
	b = ft_printf("\033[1;36m'%%010.*d' (p=-5) |%010.*d|\n", -5, pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m38. Negative Star Width and Negative Star Precision\n");
	// Crucial: w=-10 converts to '-', p=-5 converts to no precision.
	a = printf("\033[1;33m'%%*.*d' (w=-10, p=-5) |%*.*d|\n", -10, -5, pos);
	b = ft_printf("\033[1;36m'%%*.*d' (w=-10, p=-5) |%*.*d|\n", -10, -5, pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION (-1)\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", -1);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", -1);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION (INT_MIN)\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", INT_MIN);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", INT_MIN);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION (LONG_MAX)\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", LONG_MAX);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", LONG_MAX);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION (UINT_MAX)\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", UINT_MAX);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", UINT_MAX);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION (ULONG_MAX)\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", ULONG_MAX);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", ULONG_MAX);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION (9223372036854775807LL)\n");
	a = printf("\033[1;33m'%%d'        |%d|\n", 9223372036854775807LL);
	b = ft_printf("\033[1;36m'%%d'        |%d|\n", 9223372036854775807LL);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\n\033[1;34m=== UNSIGNED INTEGER (%%u) ===\n\n");

	printf("\033[1;34m--- A. Basic Width and Precision Tests ---\n\n");

	printf("\033[1;34m1. Basic unsigned (No modifiers)\n");
	a = printf("\033[1;33m'%%u'        |%u|\n", u_pos);
	b = ft_printf("\033[1;36m'%%u'        |%u|\n", u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m2. Max unsigned int (UINT_MAX)\n");
	a = printf("\033[1;33m'%%u'        |%u|\n", u_max);
	b = ft_printf("\033[1;36m'%%u'        |%u|\n", u_max);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m3. Width only (Right-justified)\n");
	a = printf("\033[1;33m'%%20u'      |%20u|\n", u_pos);
	b = ft_printf("\033[1;36m'%%20u'      |%20u|\n", u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m4. Precision only (Forces minimum digits)\n");
	a = printf("\033[1;33m'%%.10u'     |%.10u|\n", u_pos);
	b = ft_printf("\033[1;36m'%%.10u'     |%.10u|\n", u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- B. Ignored Flags ('+', ' ', '#') ---\n\n");

	printf("\033[1;34m5. Plus flag ('+') (Must be ignored)\n");
	a = printf("\033[1;33m'%%+u'       |%+u|\n", u_pos);
	b = ft_printf("\033[1;36m'%%+u'       |%+u|\n", u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m6. Space flag (' ') (Must be ignored)\n");
	a = printf("\033[1;33m'%% u'        |% u|\n", u_pos);
	b = ft_printf("\033[1;36m'%% u'        |% u|\n", u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m7. Alternate flag ('#') (Must be ignored)\n");
	a = printf("\033[1;33m'%%#u'       |%#u|\n", u_pos);
	b = ft_printf("\033[1;36m'%%#u'       |%#u|\n", u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- C. Zero Padding, Precision, and Justification ---\n\n");

	printf("\033[1;34m8. Zero-padding ('0')\n");
	a = printf("\033[1;33m'%%020u'     |%020u|\n", u_pos);
	b = ft_printf("\033[1;36m'%%020u'     |%020u|\n", u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m9. Left-justified ('-')\n");
	a = printf("\033[1;33m'%%-20u'     |%-20u|\n", u_pos);
	b = ft_printf("\033[1;36m'%%-20u'     |%-20u|\n", u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m10. Zero-padding with Precision (Crucial: '0' ignored)\n");
	a = printf("\033[1;33m'%%020.10u'  |%020.10u|\n", u_pos);
	b = ft_printf("\033[1;36m'%%020.10u'  |%020.10u|\n", u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m11. Left-justified with Zero-padding (Crucial: '0' ignored)\n");
	a = printf("\033[1;33m'%%-020u'    |%-020u|\n", u_pos);
	b = ft_printf("\033[1;36m'%%-020u'    |%-020u|\n", u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- D. Zero Value and Precision Edge Cases ---\n\n");

	printf("\033[1;34m12. Zero with precision zero (Crucial: Prints nothing)\n");
	a = printf("\033[1;33m'%%.0u'      |%.0u|\n", u_zero);
	b = ft_printf("\033[1;36m'%%.0u'      |%.0u|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m13. Zero with precision zero and width\n");
	a = printf("\033[1;33m'%%10.0u'    |%10.0u|\n", u_zero);
	b = ft_printf("\033[1;36m'%%10.0u'    |%10.0u|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m14. Zero with zero-padding (Precision zero still suppresses '0', '0' flag ignored)\n");
	a = printf("\033[1;33m'%%010.0u'   |%010.0u|\n", u_zero);
	b = ft_printf("\033[1;36m'%%010.0u'   |%010.0u|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- E. Signed to Unsigned Conversion ---\n\n");

	printf("\033[1;34m15. Negative one (-1) (Crucial: prints UINT_MAX)\n");
	a = printf("\033[1;33m'%%u' (-1)  |%u|\n", i_neg);
	b = ft_printf("\033[1;36m'%%u' (-1)  |%u|\n", i_neg);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m16. INT_MIN (Crucial: prints UINT_MAX / 2 + 1)\n");
	a = printf("\033[1;33m'%%u' (INT_MIN)|%u|\n", INT_MIN);
	b = ft_printf("\033[1;36m'%%u' (INT_MIN)|%u|\n", INT_MIN);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- F. Star-based Width/Precision Tests ---\n\n");

	printf("\033[1;34m17. Star width\n");
	a = printf("\033[1;33m'%%*u'       |%*u|\n", w, u_pos);
	b = ft_printf("\033[1;36m'%%*u'       |%*u|\n", w, u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m18. Star precision\n");
	a = printf("\033[1;33m'%%.*u'      |%.*u|\n", p, u_pos);
	b = ft_printf("\033[1;36m'%%.*u'      |%.*u|\n", p, u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m19. Negative star width (Crucial: Acts as '-' flag)\n");
	a = printf("\033[1;33m'%%*u' (w=-10) |%*u|\n", -10, u_pos);
	b = ft_printf("\033[1;36m'%%*u' (w=-10) |%*u|\n", -10, u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m20. Negative star precision (Crucial: Acts as 'no precision')\n");
	a = printf("\033[1;33m'%%.*u' (p=-5) |%.*u|\n", -5, u_pos);
	b = ft_printf("\033[1;36m'%%.*u' (p=-5) |%.*u|\n", -5, u_pos);
	printf("\033[1;35m%i / %i\n\n", a, b);


	// Assume 'a' and 'b' are defined for return values.
	int neg14 = -14;
	int neg216 = -216;
	int neg8473 = -8473;

	printf("\033[1;34m--- G. Sign Placement with Width Only ---\n\n");

	printf("\033[1;34m39. Negative number with field width (Failing case: -14, %%7d)\n");
	// Expected: [SPACE][SPACE][SPACE][SPACE][MINUS][1][4] -> "    -14"
	a = printf("\033[1;33m'%%7d'       |%7d|\n", neg14);
	b = ft_printf("\033[1;36m'%%7d'       |%7d|\n", neg14);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m40. Negative number with field width (Failing case: -8473, %%8d)\n");
	// Expected: [SPACE][SPACE][SPACE][MINUS][8][4][7][3] -> "   -8473"
	a = printf("\033[1;33m'%%8d'       |%8d|\n", neg8473);
	b = ft_printf("\033[1;36m'%%8d'       |%8d|\n", neg8473);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- H. Sign Placement with Width and Precision ---\n\n");

	printf("\033[1;34m41. Negative number with width < precision (Failing case: -216, %%10.5d)\n");
	// Number width: 5 digits + 1 sign = 6 chars. Width 10.
	// Expected: [SPACE][SPACE][SPACE][SPACE][MINUS][0][0][2][1][6] -> "    -00216"
	a = printf("\033[1;33m'%%10.5d'    |%10.5d|\n", neg216);
	b = ft_printf("\033[1;36m'%%10.5d'    |%10.5d|\n", neg216);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m42. Negative number with width > precision (Failing case: -8473, %%8.3d)\n");
	// Number width: 4 digits + 1 sign = 5 chars. Width 8. Precision 3 is ignored as it's less than digit count.
	// Expected: [SPACE][SPACE][SPACE][MINUS][8][4][7][3] -> "   -8473"
	a = printf("\033[1;33m'%%8.3d'     |%8.3d|\n", neg8473);
	b = ft_printf("\033[1;36m'%%8.3d'     |%8.3d|\n", neg8473);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- I. Sign Placement with Zero Flag and Precision (0 ignored) ---\n\n");

	printf("\033[1;34m43. Zero-padding with precision (Failing case: -216, %%010.5d)\n");
	// '0' flag ignored. Expected: [SPACE][SPACE][SPACE][SPACE][MINUS][0][0][2][1][6] -> "    -00216"
	a = printf("\033[1;33m'%%010.5d'   |%010.5d|\n", neg216);
	b = ft_printf("\033[1;36m'%%010.5d'   |%010.5d|\n", neg216);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m44. Zero-padding with smaller precision (Failing case: -8473, %%08.3d)\n");
	// '0' flag ignored. Precision ignored. Expected: [SPACE][SPACE][SPACE][MINUS][8][4][7][3] -> "   -8473"
	a = printf("\033[1;33m'%%08.3d'    |%08.3d|\n", neg8473);
	b = ft_printf("\033[1;36m'%%08.3d'    |%08.3d|\n", neg8473);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- J. Sign Placement with Zero Flag Only ---\n\n");

	printf("\033[1;34m45. Negative number with zero-padding only (Crucial: sign before zeros)\n");
	// Expected: [MINUS][0][0][0][0][0][0][2][1][6] -> "-0000000216"
	a = printf("\033[1;33m'%%010d'     |%010d|\n", neg216);
	b = ft_printf("\033[1;36m'%%010d'     |%010d|\n", neg216);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m46. Negative number with zero-padding on INT_MIN\n");
	// Expected: [MINUS][0][0]...[INT_MIN digits]
	a = printf("\033[1;33m'%%020d'     |%020d|\n", INT_MIN);
	b = ft_printf("\033[1;36m'%%020d'     |%020d|\n", INT_MIN);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- K. Hexadecimal Zero Padding Failures (%%x, %%X) ---\n\n");

	printf("\033[1;34m47. Zero-padding (%%05x, 43) (Fails: Space instead of zero padding)\n");
	// Expected: "0002b"
	a = printf("\033[1;33m'%%05x'      |%05x|\n", u_val_small);
	b = ft_printf("\033[1;36m'%%05x'      |%05x|\n", u_val_small);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m48. Large Zero-padding (%%030x, 0xFFFF) (Fails: Space instead of zero padding)\n");
	// Expected: "00000000000000000000000000ffff"
	a = printf("\033[1;33m'%%030x'     |%030x|\n", u_val_large);
	b = ft_printf("\033[1;36m'%%030x'     |%030x|\n", u_val_large);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m49. Uppercase Zero-padding (%%05X, 43) (Fails: Space instead of zero padding)\n");
	// Expected: "0002B"
	a = printf("\033[1;33m'%%05X'      |%05X|\n", u_val_small);
	b = ft_printf("\033[1;36m'%%05X'      |%05X|\n", u_val_small);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m50. Large Uppercase Zero-padding (%%030X, 0xFFFF) (Fails: Space instead of zero padding)\n");
	// Expected: "00000000000000000000000000FFFF"
	a = printf("\033[1;33m'%%030X'     |%030X|\n", u_val_large);
	b = ft_printf("\033[1;36m'%%030X'     |%030X|\n", u_val_large);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- L. Hexadecimal Zero Value Edge Cases (%%x, %%X) ---\n\n");

	printf("\033[1;34m51. Hex zero with width (%%3x, 0) (Fails: Width calculation off by 1)\n");
	// Expected: "  0"
	a = printf("\033[1;33m'%%3x'       |%3x|\n", u_zero);
	b = ft_printf("\033[1;36m'%%3x'       |%3x|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m52. Hex zero with left-justified width (%%-3x, 0) (Fails: Width calculation off by 1)\n");
	// Expected: "0  "
	a = printf("\033[1;33m'%%-3x'      |%-3x|\n", u_zero);
	b = ft_printf("\033[1;36m'%%-3x'      |%-3x|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m53. Hex zero with zero-padding (%%03x, 0) (Fails: Incorrect zero-padding)\n");
	// Expected: "000"
	a = printf("\033[1;33m'%%03x'      |%03x|\n", u_zero);
	b = ft_printf("\033[1;36m'%%03x'      |%03x|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- M. Hex Precision & Left-Justification (%%x, %%X) ---\n\n");

	printf("\033[1;34m54. Left-justified w/ precision (%%-8.5x, 34) (Fails: Incorrect space count)\n");
	// Expected: "00022   " (5 precision digits + 3 spaces = 8 chars total)
	a = printf("\033[1;33m'%%-8.5x'    |%-8.5x|\n", u_val_medium);
	b = ft_printf("\033[1;36m'%%-8.5x'    |%-8.5x|\n", u_val_medium);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m55. Left-justified w/ precision, zero value (%%-8.5x, 0) (Fails: Incorrect space count)\n");
	// Expected: "00000   " (5 precision digits + 3 spaces = 8 chars total)
	a = printf("\033[1;33m'%%-8.5x'    |%-8.5x|\n", u_zero);
	b = ft_printf("\033[1;36m'%%-8.5x'    |%-8.5x|\n", u_zero);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- N. Character Null Character Edge Cases (%%c) ---\n\n");

	printf("\033[1;34m56. Left-justified null character (%%-5c, '\\0') (Fails: Incorrect padding)\n");
	// Expected: Prints '\0' followed by 4 spaces. Return value 5.
	a = printf("\033[1;33m'%%-5c'      |%-5c|\n", '\0');
	b = ft_printf("\033[1;36m'%%-5c'      |%-5c|\n", '\0');
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m57. Right-justified null character (W=3) (%%3c, 0) (Fails: Incorrect output)\n");
	// Expected: Prints 2 spaces followed by '\0'. Return value 3. Full expected output: "{  \0}"
	a = printf("\033[1;33m'{%%3c}'      |{%3c}|\n", 0);
	b = ft_printf("\033[1;36m'{%%3c}'      |{%3c}|\n", 0);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m57. Right-justified null character (W=3) (%%3c, 0) (Fails: Incorrect output)\n");
	// Expected: Prints 2 spaces followed by '\0'. Return value 3. Full expected output: "{  \0}"
	a = printf("\033[1;33m'{%%3c}'      |{%3c}|\n", 0);
	b = ft_printf("\033[1;36m'{%%3c}'      |{%3c}|\n", 0);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m--- N. Character Null Character Edge Cases (%%c) ---\n\n");

	printf("\033[1;34m56. Left-justified null character (%%-5c, '\\0') (Fails: Incorrect padding)\n");
	// Expected: Prints the invisible '\0' followed by 4 spaces. Return value 5.
	a = printf("\033[1;33m'%%-5c'      |%-5c|\n", '\0');
	b = ft_printf("\033[1;36m'%%-5c'      |%-5c|\n", '\0');
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34m57. Right-justified null character (W=3) (%%3c, 0) (Fails: Incorrect output)\n");
	// Expected: Prints 2 spaces followed by '\0'. Return value 3 (for the %c part).
	// Total print: { + 2 spaces + \0 + } (5 characters total).
	a = printf("\033[1;33m'{%%3c}'      |{%3c}|\n", 0);
	b = ft_printf("\033[1;36m'{%%3c}'      |{%3c}|\n", 0);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PAULO SANTANA EDITION 1\n");
	a = printf("\033[1;33m|%10c|\n", '\0');
	b = ft_printf("\033[1;36m|%10c|\n", '\0');
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PAULO SANTANA EDITION 2\n");
	a = printf("\033[1;33m|%-2c%-3c%-4c*|\n", 0, 'a', 0);
	b = ft_printf("\033[1;36m|%-2c%-3c%-4c*|\n", 0, 'a', 0);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION 1\n");
	a = printf("\033[1;33m %#x \n", LONG_MIN);
	b = ft_printf("\033[1;36m %#x \n", LONG_MIN);
	printf("\033[1;35m%i / %i\n\n", a, b);

	printf("\033[1;34mEXTRA TESTS: PACO EDITION 1\n");
	a = printf("\033[1;33m %#x %#x %#x %#x %#x %#x %#x \n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	b = ft_printf("\033[1;36m %#x %#x %#x %#x %#x %#x %#x \n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\033[1;35m%i / %i\n\n", a, b);
	
	return (0);
}