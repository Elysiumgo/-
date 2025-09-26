/* 2452545 ����� ������ */

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */



//�ַ�������
int tj_strlen(const char* str)
{
    int num = 0;
    if (str==NULL||*str == '\0')
        return 0;
    for (;*str != '\0';str++) {
        num++;
    }



    return num;
}



//s2׷�ӵ�s1
char* tj_strcat(char* s1, const char* s2)
{
    
    
    if (s1 == NULL)
        return NULL;
    if (s2 == NULL)
        return s1;


   char* s1_end = s1 + tj_strlen(s1);
    while (*s2 != '\0') {
        *s1_end = *s2;
        s1_end++;
        s2++;
    }
    *s1_end = '\0';


    return s1;
}





char* tj_strncat(char* s1, const char* s2, const int len)
{
    


    if (s1 == NULL)
        return NULL;
    if (s2 == NULL)
        return s1;

    
    char* s1_end = s1 + tj_strlen(s1);
    int now_len = 0;

    while (*s2 != '\0'&&now_len<len) {
        *s1_end = *s2;
        s1_end++;
        s2++;
        now_len++;
    }

    *s1_end= '\0';
        






    return s1;
}




//����
char* tj_strcpy(char* s1, const char* s2)
{ 
   
    if ( s1 == NULL)
        return NULL;

    if (s2 == NULL) {
        *s1 = '\0';
        return s1;
    }
        


    char* begin_s1 = s1;

    if (*s2 == '\0') {
        *begin_s1 = '\0';
        return begin_s1;
    }

   

    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';





    return begin_s1;
}





//����n��
char* tj_strncpy(char* s1, const char* s2, const int len)
{
   
    if (s1 == NULL || s2 == NULL || len <= 0) 
        return s1;

    char* orig_s1 = s1;
    int copied = 0;
    const char* end = s2 + len;

   
    while (copied < len && *s2 != '\0') {
        *s1++ = *s2++;
        copied++;
    }

    return orig_s1;
}



   


//�Ƚϴ�С
int tj_strcmp(const char* s1, const char* s2)
{
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;




    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2)
            return static_cast<int>(*s1 - *s2);
        s1++;
        s2++;
    }
    
    return static_cast<int>(*s1-*s2);






    
}



char my_lowupper(char k)
{
    if (k >= 'A' && k <= 'Z')
        k += 32;
    return k;

}


//�Ƚϴ�С�����ִ�Сд
int tj_strcasecmp(const char* s1, const char* s2)
{
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;

    while (*s1 != '\0' && *s2 != '\0') {
        char c1 = my_lowupper(*s1);
        char c2 = my_lowupper(*s2);
        if (c1 != c2) {
            return c1 - c2;  // ����Сд��ĸ�Ĳ�ֵ
        }
        s1++;
        s2++;
    }

    return my_lowupper(*s1) - my_lowupper(*s2);




}

//�Ƚ�n��
int tj_strncmp(const char* s1, const char* s2, const int len)
{
   
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;





    int num = 0;
    while (*s1 != '\0' && *s2 != '\0'&&num<len) {
        if (*s1 != *s2)
            return static_cast<int>(*s1 - *s2);
        s1++;
        s2++;
        num++;
    }

    if(num==len){
        s1--;
        s2--;
    }

    
return static_cast<int>(*s1 - *s2);


 










 
}





//�Ƚ�n�������ִ�Сд
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;





    int num = 0;
    while (*s1 != '\0' && *s2 != '\0' && num < len) {
        char c1 = my_lowupper(*s1);
        char c2 = my_lowupper(*s2);
        if (c1 != c2) {
            return c1 - c2;  // ����Сд��ĸ�Ĳ�ֵ
        }
        s1++;
        s2++;
        num++;
    }

    if (num >= len) {
        s1--;
        s2--;
    }


    return my_lowupper(*s1) - my_lowupper(*s2);
}





//ת��д
char* tj_strupr(char* str)
{

    if (str == NULL)
        return NULL;




    char* str_begin = str;
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
        str++;
    }





    return str_begin;
}




//תСд
char* tj_strlwr(char* str)
{
    if (str == NULL)
        return NULL;




    char* str_begin = str;
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;
        str++;
    }





    return str_begin;
}




//������Ѱ���ַ�λ��
int tj_strchr(const char* str, const char ch)
{

    if (str == NULL)
        return 0;



    int num = 1;

    while (*str != '\0') {
        if (*str == ch)
            return num;
        str++;
        num++;
    }


    return 0;





    
}




//������Ѱ���ַ���λ��
int tj_strstr(const char* str, const char* substr)
{
    if (str == NULL||substr==NULL)
        return 0;

    int num = 1;
    const char* orig_substr = substr;

    while (*str != '\0') {
        const char* temp_str = str;
        substr = orig_substr;  // ÿ�αȽ�ǰ����substrָ��

        while (*temp_str != '\0' && *substr != '\0' && *temp_str == *substr) {
            temp_str++;
            substr++;
        }

        if (*substr == '\0')  // ��ȫƥ��
            return num;

        str++;
        num++;
    }




    return 0;


    
}




//���ҵ���Ѱ���ַ�λ��
int tj_strrchr(const char* str, const char ch)
{ 
    
    if (str == NULL)
        return 0;



    const char* str_end = str + tj_strlen(str)-1;

  
    int num = tj_strlen(str);

    while (*str_end != '\0') {
        if (*str_end == ch)
            return num;
        str_end--;
        num--;
    }


    return 0;


}





//���ҵ���Ѱ���ַ���λ��
int tj_strrstr(const char* str, const char* substr)
{
    if (str == NULL || substr == NULL)
        return 0;

    int str_len = tj_strlen(str);
    int sub_len = tj_strlen(substr);

    if (sub_len == 0) 
        return 0;  

    const char* p = str + str_len - 1;  
    const char* sub_end = substr + sub_len - 1;  
    int num = str_len;  

    while (p >= str) {
        const char* temp_p = p;
        const char* temp_sub = sub_end;
        bool matched = 1;

        while (temp_sub >= substr && temp_p >= str) {
            if (*temp_p != *temp_sub) {
                matched = 0;
                break;
            }
            temp_p--;
            temp_sub--;
        }

        if (matched && temp_sub < substr) {
            return num - sub_len + 1;  // ������ʼλ��
        }

        p--;
        num--;
    }

    return 0;




}




//����
char* tj_strrev(char* str)
{
    if (str == NULL)
        return NULL;

    char* str_begin = str;
    char* str_end = str + tj_strlen(str)-1;

    while (str_end > str) {
        char t;
        t = *str_end;
        *str_end = *str;
        *str = t;

        str_end--;
        str++;
    }

    

    return str_begin;
}
