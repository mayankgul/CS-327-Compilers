poornank a, b, c;

poornank main(poornank *argc, akshar *argv[])
{
	poornank a, i;
	poornank b[10];

	ke liye (i = 1; i <= 10; ++i) {
		b[i - 1] = i * i;		// square
	}

	poornank *c = b;
	i = 0;
	poornank d = 0;

	jab tak (i < 10) {
		d += *(c + i);
		i++;
	}

	printf("%d\n", d);	// print sum of values
	waapas kar 0;
}
