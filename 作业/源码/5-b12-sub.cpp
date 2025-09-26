/* 2452545 ����� ������ */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��return 0ֻ��һ��ʾ�����ɸı� */

/* ���������κ���ʽ���ⲿȫ�֡���̬ȫ�֡��궨�塢ֻ������ */


//�󳤶�
int tj_strlen(const char str[])
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int i = 0;
    while (str[i] != '\0') 
        i++;
    return i;

    
}

//׷��
int tj_strcat(char s1[], const char s2[])
{
    int i = 0, j = 0;

    while (s1[i] != '\0') {
        i++;
    }

    while (s2[j] != '\0') {
        s1[i++] = s2[j++];
    }
    s1[i] = '\0'; 

    return 0;




}

//׷��len��
int tj_strncat(char s1[], const char s2[], const int len)
{
    int i=0;
    while (s1[i] != '\0')
        i++;
    int j=0;
    while (s2[j] != '\0' && j < len) {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';
    return 0;




}

//����
int tj_strcpy(char s1[], const char s2[])
{
   
    int i = 0;
    while (s2[i] != '\0') {  
        s1[i] = s2[i];
        i++;
    }
    
    s1[i] = '\0';
    return 0;


}

//����len��
int tj_strncpy(char s1[], const char s2[], const int len)
{
    int i = 0;
    while (i < len && s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    
   
    return 0;

}



//�Ƚϴ�С�����Ǵ�Сд��
int tj_strcmp(const char s1[], const char s2[])
{
    int i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }

    return (unsigned char)s1[i] - (unsigned char)s2[i];

    
}




//���Ӵ�Сд���ȴ�С
int tj_strcasecmp(const char s1[], const char s2[])
{
    
    for (int i = 0; ; i++) {
        char c1 = (s1[i] >= 'A' && s1[i] <= 'Z') ? s1[i] + 32 : s1[i];
        char c2 = (s2[i] >= 'A' && s2[i] <= 'Z') ? s2[i] + 32 : s2[i];

        if (c1 != c2)
            return c1 - c2;
        if (c1 == '\0')
            return -c2;
        if (c2 == '\0')
            return c1;
    }
    return 0;
}





//�Ƚ�ǰlen�����ִ�Сд

int tj_strncmp(const char s1[], const char s2[], const int len)
{
    int i = 0;
    while (i<len) {
        
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        if (s1[i] == '\0')
            return -s2[i];
        if (s2[i] == '\0')
            return s1[i];
        i++;
    }

    return 0;


}



//�Ƚ�len���Ĵ�С�����Դ�Сд
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    int i = 0;
    for (int i = 0; i < len; i++) {
        char c1 = (s1[i] >= 'A' && s1[i] <= 'Z') ? s1[i] + 32 : s1[i];
        char c2 = (s2[i] >= 'A' && s2[i] <= 'Z') ? s2[i] + 32 : s2[i];

        if (c1 != c2) 
            return c1 - c2;
        if (c1 == '\0') 
            return -c2;  
        if (c2 == '\0')
            return c1;
    }
    return 0;

}




//ת��д
int tj_strupr(char str[])
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }

    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

//תСд
int tj_strlwr(char str[])
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    

    return 0;

    
}

//������Ѱ��ch��һ�γ��ֵ�λ��
int tj_strchr(const char str[], char ch)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ch)
            return i+1;
        i++;

    }



    return 0;



}

//������Ѱ��substr��һ�γ��ֵ�λ��

int tj_strstr(const char str[], const char substr[])
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
        int j = 0;
        while (substr[j] != '\0' && str[i + j] == substr[j]) {
            j++;
        }
        if (substr[j] == '\0') 
            return i+1;
    }
            
    return 0;

}






 
//���ҵ���Ѱ��ch��һ�γ��ֵ�λ��
int tj_strrchr(const char str[], const char ch)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    for (i;i >= 0;i--) {
        if (str[i] == ch)
            return i+1;
    }

    return 0;



}

//���ҵ���Ѱ��substr��һ�γ��ֵ�λ��
int tj_strrstr(const char str[], const char substr[])
{
    int i = 0;
    while (str[i] != '\0')
        i++;

    for (i;i >= 0;i--) {
        int j = 0;
        while (substr[j] != '\0' && str[i + j] == substr[j]) {
            j++;
        }
        if (substr[j] == '\0')
            return i + 1;
    }





    return 0; //returnֵ�ɸ�����Ҫ�޸�
}




//��ת
int tj_strrev(char str[])
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }






    return 0; //returnֵ�ɸ�����Ҫ�޸�
}
