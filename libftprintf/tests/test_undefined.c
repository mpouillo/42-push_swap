#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("\n%i\n", printf("%d%5.4%%", 123, 1));
	printf("\n%i\n", ft_printf("%d%5.4%%", 123, 1));

	printf("\n## 🛑 Type Mismatch / Argument Size\n");
	char *s = "pointer_test";

	printf("\nTEST: |%%p| with int 12345 (UB)\n");
	printf("REF: "); printf("\n%i\n", printf("|%p|", 12345));
	printf("\n%i\n", ft_printf("YOU: |%p|", 12345) - 5);

	printf("\nTEST: |%%p| with int -1 (UB/Sign Extension)\n");
	printf("REF: "); printf("\n%i\n", printf("|%p|", -1));
	printf("\n%i\n", ft_printf("YOU: |%p|", -1) - 5);

	printf("\nTEST: |%%d| with string pointer 's' (UB)\n");
	printf("REF: "); printf("\n%i\n", printf("|%d|", s));
	printf("\n%i\n", ft_printf("YOU: |%d|", s) - 5);

	printf("\nTEST: |%%p| with float 4.2f (UB)\n");
	printf("REF: "); printf("\n%i\n", printf("|%p|", 4.2f));
	printf("\n%i\n", ft_printf("YOU: |%p|", 4.2f) - 5);

	printf("\nTEST: |%%d| with long long 922...807LL (UB/Truncation)\n");
	printf("REF: "); printf("\n%i\n", printf("|%d|", 9223372036854775807LL));
	printf("\n%i\n", ft_printf("YOU: |%d|", 9223372036854775807LL) - 5);

    printf("\n## 🤯 Incorrect Format String Edge Cases\n");
    printf("---------------------------------------------------\n");

    // --- Incomplete Specifiers & Conflicting Flags ---

    printf("\nTEST: Incomplete Specifier Chain: |%%d%%5.4%%%%| with 123, 1\n");
    // Should print '123' then misinterpret '5.4' then print literal '%%'
    printf("REF: "); printf("\n%i\n", printf("|%d%5.4%%|", 123, 1));
    printf("\n%i\n", ft_printf("YOU: |%d%5.4%%|", 123, 1) - 5);

    // --- Specifier Chain Errors (Stack Mismatch) ---

    printf("\nTEST: Missing Argument for '*' (UB): |%%d%%*d| with 10\n");
    // Expected: Reads 10 for %%d, then reads garbage width for %%*d, then reads 10 as the second %%d value.
    printf("REF: "); printf("\n%i\n", printf("|%d%*d|", 10));
    printf("\n%i\n", ft_printf("YOU: |%d%*d|", 10) - 5);

    printf("\nTEST: Argument Shift: |%%s%%10d%%.2d| with \"hello\", 1, 2\n");
    // Expected: %%s reads "hello", %%10d reads 1, %%.2d reads 2. The first %%10d reads garbage.
    printf("REF: "); printf("\n%i\n", printf("|%s%10d%.2d|", "hello", 1, 2));
    printf("\n%i\n", ft_printf("YOU: |%s%10d%.2d|", "hello", 1, 2) - 5);
}