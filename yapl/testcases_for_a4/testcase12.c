poornank main()
{
    poornank n = 121;
    poornank rev = 0, rem, temp;

    temp = n;

    jab tak (temp > 0)
    {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp = temp / 10;
    }

    agar (rev == n)
    {
        n = 1;   // palindrome
    }
    warna
    {
        n = 0;   // not palindrome
    }
}