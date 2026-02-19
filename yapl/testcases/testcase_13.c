poornank main(poornank *argc, akshar argv[])
{
	poornank static, auto;
	akshar goto, restrict;
	bada dashamlav volatile;
	akshar *restrict;

	volatile = 2.435;
	union = 2.33;
	goto = 6;
	restrict = "Hello Foobar";

	waapas kar 0;
}

poornank fun()
{
	agar (1)
		a++;
	warna agar (0) //1
		b++;
	warna agar (1)
	{ //2
		agar (1)
			a++;
		warna agar (0)
			b++; //3
		warna
			c++; //4
	}
	warna
	{ //3
		agar (1)
			a++;
		warna agar (0)
			b++; //4
		warna
			c++; //5 (max depth is here)
	}
}
