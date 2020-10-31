#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
char**** get_document (char* text) {
    int dist, w_num, s_num, p_num;
    char *start, *word;
    char** sent;
    char*** para;
    char**** doc;
    
    doc=(char****)malloc(sizeof(char***));
    memset(doc, '\0', sizeof(char***));
    p_num=1;
    
    while(*text!='\0'){
        para=(char***)malloc(sizeof(char**));
        memset(para, '\0', sizeof(char**));
        s_num=1;
        
        while((*text!='\n')&&(*text!='\0')){
            sent=(char**)malloc(sizeof(char*));
            memset(sent, '\0', sizeof(char*));
            w_num=1;
            
            while(*text!='.'){
                start=text;
                while((*text!=' ')&&(*text!='.')){text++;}
                
                dist=text-start;
                word=(char*)malloc(sizeof(char)*(dist+1));
                
                memcpy(word, start, dist);
                memset(word+dist, '\0', sizeof(char));
                
                sent=realloc(sent, sizeof(char*)*(w_num+1));
                *(sent+w_num-1)=word;
                *(sent+w_num)='\0';
                
                w_num++;
                if(*text==' ')text++;
            }
            
            para=realloc(para, sizeof(char**)*(s_num+1));
            *(para+s_num-1)=sent;
            *(para+s_num)='\0';
            s_num++;
            text++;
        }
        
        doc=realloc(doc, sizeof(char***)*(p_num+1));
        *(doc+p_num-1)=para;
        *(doc+p_num)='\0';
        p_num++;
        
        if(*text=='\n')text++;
    }
    
    return doc;  
}

char* kth_word_in_mth_sentence_of_nth_paragraph (char**** document, int k, int m, int n) {
    n--;m--;k--;
    return *(*(*(document+n)+m)+k);
}

char** kth_sentence_in_mth_paragraph (char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph (char**** document, int k) {
    return document[k-1];
}
