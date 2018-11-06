#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*main den gelen buffer de�erine g�re okunan de�erin keyword ya da 
identifier oldu�una karar veren fonksiyon*/
int isKeyword(char buffer[]){
	
	// dile tan�mlanm�� keyword ler
    char keywords[11][10] = {"out","to","times","float","if","int","return","struct","loop","newline","while"};
    
	int i, flag = 0;
    
    // keywords arrayin dola��r e�er e�le�en de�er varsa flag i 1 yap�p ekrana yazd�r�r
    for(i = 0; i < 32; ++i){
    	
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    
    return flag;
}// end isKeyword
 
int main(){
	
	// de�erlerin tan�mlanmas�
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
    
    // e�er dosya ad� yanl�� girilirse hata verir.
    if(fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }// end if
    
    // dosyan�n sonuna kadar dola��r
    while((ch = fgetc(fp)) != EOF){
    	
		if ( ch == '\n'){
			satir ++;
    	}
        	
        // okunan de�er operators dizisinin i�inde bir eleman ise eleman� ekrana basar
		if(ch == operators[i]){
            printf("%d. satirda (%c) operatoru var.\n", satir, ch);
            str[i] = '\0';
        }// end if
        
        
        // okunan karakterin sat�r sonu olup olmad���n� kontrol eder
        if(ch == end_of_line[k] ){
           	printf("%d. satirda (%c) end of line var.\n", satir, ch);
           	str[k] = '\0';
       	}// end if	
              
         	
        //okunan de�er parantez_acma dizisinin i�inde bir eleman ise eleman� ekrana basar
        if (ch == parantez_acma[t] ){
           	printf("%d. satirda (%c) parantez acma var.\n", satir, ch);
           	str[t] = '\0';
       	}// end if
       		
       		
       	//okunan de�er parantez_kapama dizisinin i�inde bir eleman ise eleman� ekrana basar
		if (ch == parantez_kapama[t] ){
		   	printf("%d. satirda (%c) parantez kapama var.\n", satir, ch);
           	str[t] = '\0';
       	}// end if
       		
       	// okunan de�er dilin syntax �na uymuyor ise ka��nc� sat�rda error verdi�ini yazar.
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
                   
				/*isKeyword fonksiyonuna giden buffer de�eri 1(true) ise yani okunan karakter bo�luk ya da sat�r sonu de�il
				ve yukar�da tan�mlanan herhangi bir teki karaktere e�it de�ilse keyword ya da identifier olma durumunu sorgulamak
				i�in fonksiyona gider. E�er okunan string keyword dizisinin i�inde varsa buffer de�eri 1 e e�it olur ve ekrana 
				keyword dur basar. Yok ise else durumunda buffer de�eri 0 a e�it olur ve okunan string in identifier oldu�unu 
				anlar�z.*/
	        
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

