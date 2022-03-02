char * intToRoman(int num){
    char* roman = (char*)malloc(20 * sizeof(char));
    for (int i = 0; i< 20; i++)
    {
        roman[i] = '\0';
    }
    
    do{
        if(num/1000){
            strncat(roman, "M", 1);
            num = num-1000;
        }else if(num/900){
            strncat(roman, "CM",2);
            num = num-900;
        }else if(num/500){
            strncat(roman, "D", 1);
            num = num-500;
        }else if(num/400){
            strncat(roman, "CD", 2);
            num = num-400;
        }else if(num/100){
            strncat(roman, "C", 1);
            num = num-100;
        }else if(num/90){
            strncat(roman, "XC", 2);
            num = num-90;
        }else if(num/50){
            strncat(roman, "L", 1);
            num = num-50;
        }else if(num/40){
            strncat(roman, "XL", 2);
            num = num-40;
        }else if(num/10){
            strncat(roman, "X", 1);
            num = num-10;
        }else if(num/9){
            strncat(roman, "IX", 2);
            num = num-9;
        }else if(num/5){
            strncat(roman, "V", 1);
            num = num-5;
        }else if(num/4){
            strncat(roman, "IV", 2);
            num = num-4;
        }else if(num/1){
            strncat(roman, "I", 1);
            num--;
        }
    }while(num>0);

    return roman;
}
