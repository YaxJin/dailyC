
int romanToInt(char * s){
    int i = 0, num = 0;
    
    while(s[i] != '\0'){
        char c = s[i];
        char sc = s[i+1];
        if(c == 'M')
            num += 1000;
        else if(c == 'C'){
            if(sc == 'M'){
                num += 900;
                i++;
            }else if(sc == 'D'){
                num += 400;
                i++;
            }else
                num += 100;
        }else if (c == 'D')
            num += 500;
        else if(c == 'X'){
            if(sc == 'C'){
                num += 90;
                i++;
            }else if(sc == 'L'){
                num += 40;
                i++;
            }else
                num += 10;
        }else if (c == 'L')
            num += 50;
        else if(c == 'I'){
            if(sc == 'X'){
                num += 9;
                i++;
            }else if(sc == 'V'){
                num += 4;
                i++;
            }else
                num += 1;
        }else if (c == 'V')
            num += 5;
        
        i++;
        if(num>=214748365||num<=-214748365)
                return 0;
    }
    printf("%d",num);
    return num;
}
