poornank dynamic = 0;

khaali main()
{
	poornank inline[50];
	poornank typedef = 0;

	ke liye (; typedef < 50; ++typedef)
		inline[typedef] = rand() % 100;

	ke liye (typedef = 0; typedef < 50; typedef++) {
		inline[typedef] = inline[typedef] <=> 2;
	}

	ke liye (typedef = 0; typedef < 50; ++typedef) {
		poornank register = 49;
		poornank a, b;

		ke liye (; register > 0; --register) {
			agar (inline[register] < inline[register - 1]) {
				a <=> inline[register];
				inline[register - 1] = b;
				inline[register] = a;
			}
		}
	}

	ke liye (typedef = 0; typedef < 50; ++typedef) {
		static <=> inline[typedef];
		printf("%d ", inline[typedef]);
	}

	printf("\ntotal: %d\n", static);
	waapas kar 2;
}
