void main()
{
    struct foo {
    char a[20];
    };

    struct bar {
    char* a;
    };
    printf("%zu\n", sizeof(struct foo));
    printf("%zu\n", sizeof(struct bar));
}