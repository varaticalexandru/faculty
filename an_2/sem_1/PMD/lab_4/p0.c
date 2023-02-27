

int main()
{

    __asm__(
        "movl %edx, %eax\n\t"
        "addl $2, %eax\n\t"
    );
}