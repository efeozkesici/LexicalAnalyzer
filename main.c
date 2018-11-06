#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*main den gelen buffer deðerine göre okunan deðerin keyword ya da 
identifier olduðuna karar veren fonksiyon*/
int isKeyword(char buffer[]){
	
	// dile tanýmlanmýþ keyword ler
    char keywords[11][10] = {"out","to","times","float","if","int","return","struct","loop","newline","while"};
    
	int i, flag = 0;
    
    // keywords arrayin dolaþýr eðer eþleþen deðer varsa flag i 1 yapýp ekrana yazdýrýr
    for(i = 0; i < 32; ++i){
    	
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    
    return flag;
}// end isKeyword
 
int main(){
	
	// deðerlerin tanýmlanmasý
	char end_of_line[] = {"."};
	char parantez_acma[] = {"["};
	char parantez_kapama[] = {"]"};
    char ch, buffer[15], operators[] = "+-*/%=";
    char errors[] = {'+-', '-+', ' -', '--', '+'};
    
	FILE *fp;
    
	int i,j,k,t=0;
    char str[100];
    int satir = 1;
    
    char dosya_ismi;
    
    fp = fopen("b.ba","r");
    
    printf("Please enter the file:");
    
	scanf("%c", &dosya_ismi);
    
	printf("\n");
    
    // eðer dosya adý yanlýþ girilirse hata verir.
    if(fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }// end if
    
    // dosyanýn sonuna kadar dolaþýr
    while((ch = fgetc(fp)) != EOF){
    	
		if ( ch == '\n'){
			satir ++;
    	}
        	
        // okunan deðer operators dizisinin içinde bir eleman ise elemaný ekrana basar
		if(ch == operators[i]){
            printf("%d. satirda (%c) operatoru var.\n", satir, ch);
            str[i] = '\0';
        }// end if
        
        
        // okunan karakterin satýr sonu olup olmadýðýný kontrol eder
        if(ch == end_of_line[k] ){
           	printf("%d. satirda (%c) end of line var.\n", satir, ch);
           	str[k] = '\0';
       	}// end if	
              
         	
        //okunan deðer parantez_acma dizisinin içinde bir eleman ise elemaný ekrana basar
        if (ch == parantez_acma[t] ){
           	printf("%d. satirda (%c) parantez acma var.\n", satir, ch);
           	str[t] = '\0';
       	}// end if
       		
       		
       	//okunan deðer parantez_kapama dizisinin içinde bir eleman ise elemaný ekrana basar
		if (ch == parantez_kapama[t] ){
		   	printf("%d. satirda (%c) parantez kapama var.\n", satir, ch);
           	str[t] = '\0';
       	}// end if
       		
       	// okunan deðer dilin syntax ýna uymuyor ise kaçýncý satýrda error verdiðini yazar.
       	if(ch == errors[t]){
       		printf("%d. satirda hatali kod kullanimi.\n");
       		str[t] ='\0';
		}
			
		 
        if(isalnum(ch)){
            buffer[j++] = ch;
        } // end if
           
        else if((ch == ' ' || ch == '\n') && (j != 0)){
                buffer[j] = '\0';
                j = 0;
                   
				/*isKeyword fonksiyonuna giden buffer deðeri 1(true) ise yani okunan karakter boþluk ya da satýr sonu deðil
				ve yukarýda tanýmlanan herhangi bir teki karaktere eþit deðilse keyword ya da identifier olma durumunu sorgulamak
				için fonksiyona gider. Eðer okunan string keyword dizisinin içinde varsa buffer deðeri 1 e eþit olur ve ekrana 
				keyword dur basar. Yok ise else durumunda buffer deðeri 0 a eþit olur ve okunan string in identifier olduðunu 
				anlarýz.*/
	        
                if(isKeyword(buffer) == 1){
                    printf("%d. satirda (%s) keyword u var.\n", satir, buffer);
                }
                else{
                    printf("%d. satirda (%s) identifier i var.\n", satir, buffer);
                }
        }// end else if
           
    } // end while
    
    fclose(fp);
    
    return 0;
} // end main

