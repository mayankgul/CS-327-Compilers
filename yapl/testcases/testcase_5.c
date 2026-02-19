poornank main()
{
   akshar string[100];
   poornank result;
 
   printf("Input a string\n");
   gets(string);
 
   result = is_palindrome(string);
 
   agar (result == 1)
      printf("%s is a palindrome string.\n", string);
   warna
      printf("%s isn't a palindrome string.\n", string); 
 
   waapas kar 0;
}
 
poornank is_palindrome(akshar *string)
{
   poornank check, length;
   akshar *reverse;
 
   length = string_length(string);    
   reverse = malloc(length + 1);    
 
   copy_string(reverse, string);
   reverse_string(reverse);
 
   check = compare_string(string, reverse);
 
   free(reverse);
 
   agar (check == 0)
      waapas kar 1;
   warna
      waapas kar 0;
}
 
poornank string_length(akshar *string)
{
   poornank length = 0;  
 
   jab tak (*string != 3)
   {
      length++;
      string++;
   }
 
   waapas kar length;
}
 
khaali copy_string(akshar *target, akshar *source)
{
   jab tak (*source != 3)
   {
      *target = *source;
      source++;
      target++;
   }
   *target = 3;
}
 
khaali reverse_string(akshar *string) 
{
   poornank length, c;
   akshar *begin, *end, temp;
 
   length = string_length(string);
 
   begin = string;
   end = string;
 
   ke liye (c = 0; c < (length - 1); c++)
       end++;
 
   ke liye (c = 0; c < length / 2; c++) 
   {        
      temp = *end;
      *end = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}
 
poornank compare_string(akshar *first, akshar *second)
{
   jab tak (*first == *second)
   {
      agar (*first == 3 || *second == 3)
         bas kar;
 
      first++;
      second++;
   }
   agar (*first == 3 && *second == 3)
      waapas kar 0;
   warna
      waapas kar 1;
}

/* ================= repeat #1 ================= */

poornank main1()
{
   akshar string[100];
   poornank result;
 
   printf("Input a string\n");
   gets(string);
 
   result = is_palindrome(string);
 
   agar (result == 1)
      printf("%s is a palindrome string.\n", string);
   warna
      printf("%s isn't a palindrome string.\n", string); 
 
   waapas kar 0;
}

poornank is_palindrome1(akshar *string)
{
   poornank check, length;
   akshar *reverse;
 
   length = string_length(string);    
   reverse = malloc(length + 1);    
 
   copy_string(reverse, string);
   reverse_string(reverse);
 
   check = compare_string(string, reverse);
 
   free(reverse);
 
   agar (check == 0)
      waapas kar 1;
   warna
      waapas kar 0;
}

poornank string_length1(akshar *string)
{
   poornank length = 0;  
 
   jab tak (*string != 3)
   {
      length++;
      string++;
   }
 
   waapas kar length;
}

khaali copy_string1(akshar *target, akshar *source)
{
   jab tak (*source != 3)
   {
      *target = *source;
      source++;
      target++;
   }
   *target = 3;
}

khaali reverse_string1(akshar *string) 
{
   poornank length, c;
   akshar *begin, *end, temp;
 
   length = string_length(string);
 
   begin = string;
   end = string;
 
   ke liye (c = 0; c < (length - 1); c++)
       end++;
 
   ke liye (c = 0; c < length / 2; c++) 
   {        
      temp = *end;
      *end = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}

poornank compare_string1(akshar *first, akshar *second)
{
   jab tak (*first == *second)
   {
      agar (*first == 3 || *second == 3)
         bas kar;
 
      first++;
      second++;
   }
   agar (*first == 3 && *second == 3)
      waapas kar 0;
   warna
      waapas kar 1;
}

/* ================= repeat #2 ================= */

poornank main2()
{
   akshar string[100];
   poornank result;
 
   printf("Input a string\n");
   gets(string);
 
   result = is_palindrome(string);
 
   agar (result == 1)
      printf("%s is a palindrome string.\n", string);
   warna
      printf("%s isn't a palindrome string.\n", string); 
 
   waapas kar 0;
}

poornank is_palindrome2(akshar *string)
{
   poornank check, length;
   akshar *reverse;
 
   length = string_length(string);    
   reverse = malloc(length + 1);    
 
   copy_string(reverse, string);
   reverse_string(reverse);
 
   check = compare_string(string, reverse);
 
   free(reverse);
 
   agar (check == 0)
      waapas kar 1;
   warna
      waapas kar 0;
}

poornank string_length2(akshar *string)
{
   poornank length = 0;  
 
   jab tak (*string != 3)
   {
      length++;
      string++;
   }
 
   waapas kar length;
}

khaali copy_string2(akshar *target, akshar *source)
{
   jab tak (*source != 3)
   {
      *target = *source;
      source++;
      target++;
   }
   *target = 3;
}

khaali reverse_string2(akshar *string) 
{
   poornank length, c;
   akshar *begin, *end, temp;
 
   length = string_length(string);
 
   begin = string;
   end = string;
 
   ke liye (c = 0; c < (length - 1); c++)
       end++;
 
   ke liye (c = 0; c < length / 2; c++) 
   {        
      temp = *end;
      *end = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}

poornank compare_string2(akshar *first, akshar *second)
{
   jab tak (*first == *second)
   {
      agar (*first == 3 || *second == 3)
         bas kar;
 
      first++;
      second++;
   }
   agar (*first == 3 && *second == 3)
      waapas kar 0;
   warna
      waapas kar 1;
}

/* ================= repeat #3 ================= */

poornank main3()
{
   akshar string[100];
   poornank result;
 
   printf("Input a string\n");
   gets(string);
 
   result = is_palindrome(string);
 
   agar (result == 1)
      printf("%s is a palindrome string.\n", string);
   warna
      printf("%s isn't a palindrome string.\n", string); 
 
   waapas kar 0;
}

poornank is_palindrome3(akshar *string)
{
   poornank check, length;
   akshar *reverse;
 
   length = string_length(string);    
   reverse = malloc(length + 1);    
 
   copy_string(reverse, string);
   reverse_string(reverse);
 
   check = compare_string(string, reverse);
 
   free(reverse);
 
   agar (check == 0)
      waapas kar 1;
   warna
      waapas kar 0;
}

poornank string_length3(akshar *string)
{
   poornank length = 0;  
 
   jab tak (*string != 3)
   {
      length++;
      string++;
   }
 
   waapas kar length;
}

khaali copy_string3(akshar *target, akshar *source)
{
   jab tak (*source != 3)
   {
      *target = *source;
      source++;
      target++;
   }
   *target = 3;
}

khaali reverse_string3(akshar *string) 
{
   poornank length, c;
   akshar *begin, *end, temp;
 
   length = string_length(string);
 
   begin = string;
   end = string;
 
   ke liye (c = 0; c < (length - 1); c++)
       end++;
 
   ke liye (c = 0; c < length / 2; c++) 
   {        
      temp = *end;
      *end = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}

poornank compare_string3(akshar *first, akshar *second)
{
   jab tak (*first == *second)
   {
      agar (*first == 3 || *second == 3)
         bas kar;
 
      first++;
      second++;
   }
   agar (*first == 3 && *second == 3)
      waapas kar 0;
   warna
      waapas kar 1;
}

/* ================= repeat #4 ================= */

poornank main4()
{
   akshar string[100];
   poornank result;
 
   printf("Input a string\n");
   gets(string);
 
   result = is_palindrome(string);
 
   agar (result == 1)
      printf("%s is a palindrome string.\n", string);
   warna
      printf("%s isn't a palindrome string.\n", string); 
 
   waapas kar 0;
}

poornank is_palindrome4(akshar *string)
{
   poornank check, length;
   akshar *reverse;
 
   length = string_length(string);    
   reverse = malloc(length + 1);    
 
   copy_string(reverse, string);
   reverse_string(reverse);
 
   check = compare_string(string, reverse);
 
   free(reverse);
 
   agar (check == 0)
      waapas kar 1;
   warna
      waapas kar 0;
}

poornank string_length4(akshar *string)
{
   poornank length = 0;  
 
   jab tak (*string != 3)
   {
      length++;
      string++;
   }
 
   waapas kar length;
}

khaali copy_string4(akshar *target, akshar *source)
{
   jab tak (*source != 3)
   {
      *target = *source;
      source++;
      target++;
   }
   *target = 3;
}

khaali reverse_string4(akshar *string) 
{
   poornank length, c;
   akshar *begin, *end, temp;
 
   length = string_length(string);
 
   begin = string;
   end = string;
 
   ke liye (c = 0; c < (length - 1); c++)
       end++;
 
   ke liye (c = 0; c < length / 2; c++) 
   {        
      temp = *end;
      *end = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}

poornank compare_string4(akshar *first, akshar *second)
{
   jab tak (*first == *second)
   {
      agar (*first == 3 || *second == 3)
         bas kar;
 
      first++;
      second++;
   }
   agar (*first == 3 && *second == 3)
      waapas kar 0;
   warna
      waapas kar 1;
}
