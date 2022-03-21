// ************************************** ѧ������ϵͳ **************************************
// ���ߣ�JWven
// �汾��v1.3
// ʱ�䣺2022.3.20  20:50  ������
// ˵�����޸�������bug��������ļ��洢ģ��;����������Ϊȫ�ֱ��������ٺ���֮������Ĵ��ݣ�ֱ�Ӷ�ȫ��
//       �������в���;������ͷ�ļ�
// ���Ż���
//        1.�ɼ�ͳ�ƣ��꼶�ܷ���ߣ�������ߣ�����ƽ����ѧ���������༶�ܷ���ߡ�������������ߡ�ƽ����
//                    ����
//        2.��ǿ�˻���������
//        3.�����Ż�
//        4.�㷨�Ż�(�����㷨�������㷨)
//        5.�Ƿ����봦�� 
// *****************************************************************************************

// ͷ�ļ�
#include "stadef.h"

// ģ��һ���ļ���д
/*********************************** �ļ����뺯�� ***********************************/  
void read_file(char * file_name)  
{
    FILE * fp = NULL;                               // �ļ�ָ��
    char data_temp[10] = {'\0'};                    // �洢һ����ĳ������
    char data_row[100] = {'\0'};                    // �洢һ�е�����
    int i,j;                                        // ѭ���м�����
    
    printf("�ļ�������.......\n");
    // ���ļ�
    if ((fp = fopen(file_name, "r")) == NULL)       // �ļ���ʧ��
    {
        printf("Can not open file!\n");
        exit(0);
    }

    // ��������
    Student * head_r;                               // ͷָ��
    Student * p1, * p2;                             // �ƶ����
    n = 0;                                          // ��������������������
    p1 = p2 = (Student *)malloc(LEN);               // �����ڴ�

    // ���ļ��ж�ȡ���ݣ�����������������
    fgets(data_row, 100, fp);                       // ���Ե�һ�У���һ��Ϊ���ݱ�ǩ��
    fgets(data_row, 100, fp);                       // ����һ�У��ŵ�����data_row��
    data_input(p1,data_row);                        // ���������ݴ���������

    head = NULL;                                    // ͷָ��ָ��NULL
    while (!feof(fp))                               // δ���ļ���β��������ȡ
    {   
        n = n + 1;                                  // �������һ������������һ��
        if (n == 1)                                 // ����ǵ�һ�����
            head = p1;                              // ͷָ��ָ���һ�����
        else                                        // ������һ��֮��Ľ��
            p2->next = p1;                          // ǰһ�����ָ��ǰ���
        
        p2 = p1;                                    // �ѵ�ǰ��㸳��p2
        p1 = (Student *)malloc(LEN);                // ������һ���½��
        fgets(data_row, 100, fp);                   // �����µ�һ�У��ŵ�������
        data_input(p1,data_row);                    // ���������ݴ�������ŷ��
    }
    p2->next = NULL;                                // ���һ�����ָ��NULL
    fclose(fp);                                     // �ر��ļ�
    printf("�ļ�������ɣ�\n");
}

/*********************************** ����д�뺯�� ***********************************/ 
void data_input(Student * p1, char data_row[100])
{   
    char data_temp[10] = {'\0'};                    // �洢һ����ĳ������
    int i, j;

    for (i = 0; data_row[i] != ','; i++)            // ������д������
    {
        p1->name[i] = data_row[i];
        p1->name[i+1] = '\0';
    }
    i++;
    /************ ����д������ ************/
    for(j = 0;data_row[i] != ','; j++, i++)         // ���ζ��룬ֱ����������(csv�ļ���ʽ������)
        data_temp[j] = data_row[i];
    p1->continue_drop = atoi(data_temp);
    for (int k = j; k >= 0; k--)                    // data_temp�������ÿգ���Ϊatoi�����Ὣ���������������һ��ת��(��ϸ���ĵ�)
        data_temp[k] = '\0';
    i++;                                            // i++��������

    for(j = 0;data_row[i] != ','; j++, i++)       
        data_temp[j] = data_row[i];
    p1->student_id = atol(data_temp);
    for (int k = j; k >= 0; k--)
        data_temp[k] = '\0';
    i++;
    
    for(j = 0;data_row[i] != ','; j++, i++)       
        data_temp[j] = data_row[i];
    p1->gender = atoi(data_temp);
    for (int k = j; k >= 0; k--)
        data_temp[k] = '\0';
    i++;

    for(j = 0;data_row[i] != ','; j++, i++)       
        data_temp[j] = data_row[i];
    p1->grade= atoi(data_temp);
    for (int k = j; k >= 0; k--)
        data_temp[k] = '\0';
    i++;

    for(j = 0;data_row[i] != ','; j++, i++)       
        data_temp[j] = data_row[i];
    p1->class = atoi(data_temp);
    for (int k = j; k >= 0; k--)
        data_temp[k] = '\0';
    i++;
    
    for(j = 0;data_row[i] != ','; j++, i++)       
        data_temp[j] = data_row[i];
    p1->chinese_marks = atof(data_temp);
    for (int k = j; k >= 0; k--)
        data_temp[k] = '\0';
    i++;

    for(j = 0;data_row[i] != ','; j++, i++)       
        data_temp[j] = data_row[i];
    p1->english_marks = atof(data_temp);
    for (int k = j; k >= 0; k--)
        data_temp[k] = '\0';
    i++;

    for(j = 0;data_row[i] != '\n'; j++, i++)       
        data_temp[j] = data_row[i];
    p1->math_marks = atof(data_temp);
    for (int k = j; k >= 0; k--)
        data_temp[k] = '\0';
}

/*********************************** д���ļ����� ***********************************/
void write_file(char * filename)
{
    FILE * fp;
    // �������ݱ�ǩ
    char * row = "name,continue_drop,student_id,gender, grade,class,Chinese_marks,english_marks,math_marks\n";
    Student * p = head;
    if ((fp = fopen(filename, "w")) == NULL)        // �ļ���ʧ��
    {
        printf("Open the file error!\n");
        exit(0);
    }    
    fputs(row,fp);                                  // �����ǩ��

    while (p != NULL)                               // ���б�������
    {
        for (int i = 0; p->name[i] != '\0'; i++)    // ��������
            fprintf(fp,"%c",p->name[i]);
        // ������ֵ������(ʵ�����ļ������ַ���ʽ�洢)
        fprintf(fp,",%d,%ld,%d,%d,%d,%.2f,%.2f,%.2f\n",p->continue_drop,p->student_id,p->gender,
                p->grade,p->class,p->chinese_marks,p->english_marks,p->math_marks);
        p = p->next;                                // �ƶ����
    }
    fprintf(fp,"\n");                               // ���ļ�ĩβ��ӻ��з�����������´���Ҫ������ļ�
    printf("Save successfully!\n");
    fclose(fp);
}


// ģ�������������
/*********************************** �ͷ������� ***********************************/  
void disposal_LinkList(Student * headNode)
{
    Student * nextNode;                         // ��һ�����
    Student * curNode;                          // ��ǰ���
	if (headNode == NULL)                       // ���Ϊ�ձ�
	{
        return;
	}
	//�������,�ǲ����ͷ�ڵ�ģ���˴ӵ�һ�������ݵĽڵ㿪ʼ�ͷ�
	curNode = headNode->next;                   // ��ǰ���ָ���һ�����
	while (curNode != NULL)                     // δ��������β�������ͷ�
	{
		nextNode = curNode->next;               //�ȴ�����һ���ڵ��λ��
		free(curNode);                          // �ͷŵ�ǰ���
		curNode = nextNode;	                    // ��ǰ���ָ����һ�����
	}
	free(headNode);                             //�ͷ�ͷ���
	headNode = NULL;	                        //ͷ���ָ���ÿ�
}

/*********************************** �����㺯�� ***********************************/
void insert(Student * stud)
{
    // ��������Ҫ����Ľ��
    Student * p0, * p1, *p2;            // ����ָ��
    p1 = head;                          // p1ָ���һ�����
    p0 = stud;                          // p0ָ����Ҫ������½��

    if (head == NULL)                   // ����ǿ���������������Ϊ��һ�����
    {
        head = p0;
        p0->next = NULL;
    }
    else                                // �ǿ�����
    {
        while ((p0->student_id > p1->student_id) && (p1->next != NULL))    // ��û������λ�û�û������β
        {
            p2 = p1;                    // ���浱ǰ���
            p1 = p1->next;              // ����������һ�����
        }

        if (p0->student_id <= p1->student_id)         // �ҵ���
        {
            if (p1 == head)             // ���뵽��һ�����֮ǰ
                head = p0;
            else
                p2->next = p0;          // ����p1֮ǰ��p2֮��

            p0->next = p1;              // p0(�½��)ָ��p1
        }
        else                            // û�ҵ�(���ǲ嵽β���֮��)
        {
            p1->next = p0;             
            p0->next = NULL;
        }
    }
    n = n + 1;                          // �����+1
}

/********************************* ��������(��ѧ��) *********************************/
void sort()
{
    // �м����
    char name_t[7];                      // ����
    int continue_drop_t;                 // �Ƿ��ڶ�
    long student_id_t;                   // ѧ��
    int gender_t;                        // �Ա�
    int grade_t;                         // �꼶
    int class_t;                         // ���
    float chinese_marks_t;               // ���ĳɼ�
    float english_marks_t;               // Ӣ��ɼ�
    float math_marks_t;                  // ��ѧ�ɼ�

    Student * p1, * p2;                  // �ƶ����

    // ����
    for (int i = 0; i < n-1; i++)
    {
        p2 = head;
        p1 = p2->next;
        for (int j = 0; j < n-1; j++)
        {
            if (p2->student_id > p1->student_id)    // ��������
            {
                // ֻ�������������򽻻������������Ľ�㽻���������罻���������
                for (int k = 0; k < 7; k++)
                    name_t[k] = p1->name[k];
                continue_drop_t = p1->continue_drop;
                student_id_t = p1->student_id;
                gender_t = p1->gender;
                grade_t = p1->grade;
                class_t = p1->class;
                chinese_marks_t = p1->chinese_marks;
                english_marks_t = p1->english_marks;
                math_marks_t = p1->math_marks;
                
                for (int k = 0; k < 7; k++)
                    p1->name[k] = p2->name[k];
                p1->continue_drop = p2->continue_drop;
                p1->student_id = p2->student_id;
                p1->gender = p2->gender;
                p1->grade = p2->grade;
                p1->class = p2->class;
                p1->chinese_marks = p2->chinese_marks;
                p1->english_marks = p2->english_marks;
                p1->math_marks = p2->math_marks;

                for (int k = 0; k < 7; k++)
                    p2->name[k] = name_t[k];
                p2->continue_drop = continue_drop_t;
                p2->student_id = student_id_t;
                p2->gender = gender_t;
                p2->grade = grade_t;
                p2->class = class_t;
                p2->chinese_marks = chinese_marks_t;
                p2->english_marks = english_marks_t;
                p2->math_marks = math_marks_t;
            }
            p2 = p1;
            p1 = p1->next;
        }
    }

    // return head;
}


// ģ��������������
/*********************************** ���ѧ������ ***********************************/
void add()
{
    int length = 0;                     // �洢��������ĳ���
    Student * new;                      // �½��
    char data_row[100] = {'\0'};        // �洢�����ݣ����½������
    
    printf("\n��������ӵ�ѧ����Ϣ����','�ָ���(����0�˳�)\n");
    printf("��ʽ��name, continue_drop, student_id, gender, grade, class, Chinese_marks, english_marks, math_marks\n");
    gets(data_row);                     // ����һ�У�ע�����ﲻ��ȡ���з�
    length = strlen(data_row);
    data_row[length] = '\n';            // �����������ݵĺ�����ӻ��з���data_input���������Ҫ���ݻ��з��ж����ݽ�β
    while (data_row[0] != '0')
    {   
        new = (Student *) malloc(LEN);  // �����ڴ�
        data_input(new, data_row);      // ���ַ����ݴ�����
        insert(new);                    // ���½��������뵽������
        printf("��ӳɹ���\n");
        print_personal(new);
        printf("\n��������ӵ�ѧ����Ϣ����','�ָ���(����0�˳�)\n");
        printf("��ʽ��name, continue_drop, student_id, gender, grade, class, Chinese_marks, english_marks, math_marks\n");
        gets(data_row);
        length = strlen(data_row);
        data_row[length] = '\n';
    }
}

/*********************************** ɾ��ѧ������ ***********************************/ 
void clear()
{
    long id;                             // ѧ��ID
    Student * p1, *p2;                   // �ƶ�ָ��
    char confirm = 'Y';
    printf("��������Ҫɾ��ѧ����ѧ��(����0�˳�)��");
    scanf("%ld", &id);
    getchar();                           // �������з�

    while (id != 0)                      // �����벻����0
    {
        if (head == NULL)                // ����ǿձ�
        {
            printf("\nlist null!\n");
            return;
        }
        p1 = head;                       // p1ָ���һ�����
        while (id != p1->student_id && p1->next != NULL)      // ��ʼ������ֱ���ҵ����ߵ�������β
        {
            p2 = p1;        
            p1 = p1->next;              // p2ָ����һ����㣬��ֹ�䶪ʧ�� p1ָ����һ����㣬��������
        }
        if (id == p1->student_id)       // �ҵ���
        {
            printf("��Ҫɾ����\n");
            print_personal(p1);         // ��ӡ����ѧ����Ϣ
            printf("�Ƿ�ȷ��ɾ����ѧ����Ϣ��(Y/N)\n");
            confirm = getchar();        // ����Y or N
            getchar();
            if (confirm == 'Y')         // ȷ��ɾ��
            {
                if (p1 == head)         // ����ҵ����ǵ�һ����㣬��ɾ��ͷ���
                    head = p1->next;    // ��ͷ���ָ��ڶ�����㣬������һ�����
                else                    
                    p2->next = p1->next;// ����p1�����㣺��֮ǰ�Ľ�㣨��p2��ָ��p1֮��һ�����

                printf("ɾ���ɹ���\n");
                n = n - 1;              // �����-1
            }
            else                        // ȡ��ɾ��
                printf("ȡ��ɾ��\n");
        }
        else                            // û���ҵ�
            printf("student:%ld not benn found!\n", id);
        
        printf("��������Ҫɾ��ѧ����ѧ��(����0�˳�)��");
        scanf("%ld", &id);
        getchar();                      // �������з�
    }
}

/*********************************** ����ѧ������ ***********************************/  
void seek()
{
    long id;                            // ѧ��ID
    Student * p1, *p2;                  // �ƶ����
    
    printf("��������Ҫ����/�޸�ѧ����ѧ��(����0�˳�)��");
    scanf("%ld", &id);
    getchar();                          // �������з�

    while (id != 0)                     // �����벻Ϊ0
    {
        if (head == NULL)               // ����ǿձ�
        {
            printf("\nlist null!\n");
            return;                     // ���ؿ�ָ��
        }

        p1 = head;                      // p1ָ���һ�����
        while (id != p1->student_id && p1->next != NULL)      // ��ʼ������ֱ����������β
        {
            p2 = p1;        
            p1 = p1->next;              // p2ָ����һ����㣬��ֹ�䶪ʧ�� p1ָ����һ����㣬��������
        }

        if (id == p1->student_id)       // �ҵ���
        {
            print_personal(p1);         // ��ӡ��ѧ����Ϣ
        }
        else                            // û���ҵ�
        {
            printf("student:%ld was not be found!\n", id);
            p1 = NULL;                  // p1�ÿգ���ֱ�ӷ��أ���Ϊ��Ҫ��������
        }
        printf("��������Ҫ����/�޸�ѧ����ѧ��(����0�˳�)��");
        scanf("%ld", &id);
        getchar();                      // �������з�

    }
}

/*********************************** �޸���Ϣ���� ***********************************/
void change()
{
    Student * p, * p2;                                  // �ƶ����
    char ch, n[7];                                      // ѡ��洢���ֵ�����
    char data_row[100] = {'\0'};                        // ����һ������
    long id = 0;                                        // ѧ��ID
    int length;
    printf("��������Ҫ����/�޸�ѧ����ѧ��(����0�˳�)��");
    scanf("%ld", &id);
    getchar();                                          // �������з�
    while (id != 0)                                     // �����벻Ϊ0
    {
        if (head == NULL)                               // ����ǿձ�
        {
            printf("\nlist null!\n");
            return;                                     // ���ؿ�ָ��
        }

        p = head;                                       // p1ָ���һ�����
        while (id != p->student_id && p->next != NULL)  // ��ʼ������ֱ����������β
        {
            p2 = p;        
            p = p->next;                                // p2ָ����һ����㣬��ֹ�䶪ʧ�� p1ָ����һ����㣬��������
        }

        if (id == p->student_id)                        // �ҵ���
        {
            printf("�㽫Ҫ�޸ĵ�ѧ����\n");
            print_personal(p);                          // ��ӡ��Ҫ�޸ĵ�ѧ����Ϣ
        }
        else                                            // û���ҵ�
        {
            printf("student:%ld was not be found!\n", id);
            goto Enter;                                 // �������������������ѧ��ID
        }
        
        printf("\n***************** ��ѡ����Ҫ�޸ĵ���Ŀ *****************\n");
        printf(" A: ����       B: �Ա�       C: ѧ��       D: ��У״̬\n");
        printf(" E: �꼶       F: ���       G: ���ĳɼ�    H��Ӣ��ɼ�\n");
        printf(" I: ��ѧ�ɼ�    J:�޸�������Ϣ              0: �˳��޸�\n");
        printf("******************************************************\n");
        scanf("%c", &ch);
        getchar();
        while (ch != '0')
        {
            switch (ch)                                 // ѡ��
            {
                case 'A':
                    printf("�������޸�Ϊ��");
                    scanf("%s", n);
                    getchar();                          // �������з�������ÿ����һ�ζ�Ҫ��������
                    for (int i = 0; i < 7; i++) 
                        p->name[i] = n[i];
                    printf("�޸���ɣ�\n");
                    break;
                case 'B':
                    printf("���Ա��޸�Ϊ��");
                    scanf("%d", &p->gender);
                    getchar();
                    printf("�޸���ɣ�\n");
                    break;
                case 'C':
                    printf("��ѧ���޸�Ϊ��");
                    scanf("%ld", &p->student_id);
                    getchar();
                    sort();                     // ���ѧ�ŷ����仯����������������
                    printf("�޸���ɣ�\n");
                    break;
                case 'D':
                    printf("����У״̬�޸�Ϊ��");
                    scanf("%d", &p->continue_drop);
                    getchar();
                    printf("�޸���ɣ�\n");
                    break;
                case 'E':
                    printf("���꼶�޸�Ϊ��");
                    scanf("%d", &p->grade);
                    getchar();
                    printf("�޸���ɣ�\n");
                    break;
                case 'F':
                    printf("���༶�޸�Ϊ��");
                    scanf("%d", &p->class);
                    getchar();
                    printf("�޸���ɣ�\n");
                    break;
                case 'G':
                    printf("�����ĳɼ��޸�Ϊ��");
                    scanf("%f", &p->chinese_marks);
                    getchar();
                    printf("�޸���ɣ�\n");
                    break;
                case 'H':
                    printf("��Ӣ���޸�Ϊ��");
                    scanf("%f", &p->english_marks);
                    getchar();
                    printf("�޸���ɣ�\n");
                    break;
                case 'I':
                    printf("����ѧ�ɼ��޸�Ϊ��");
                    scanf("%f", &p->math_marks);
                    getchar();
                    printf("�޸���ɣ�\n");
                    break;
                case 'J':
                    printf("���������������,�ö��ŷָ���\n");
                    printf("��ʽ��name,continue_drop,student_id,gender, grade,class,Chinese_marks,english_marks,math_marks\n");
                    scanf("%s", data_row);           
                    getchar();
                    length = strlen(data_row);
                    data_row[length] = '\n';
                    data_input(p, data_row);
                    sort();                  // ���ѧ�ŷ����仯����������������
                    printf("�޸���ɣ�\n");
                    break;
                default:
                    break;
            }  
        printf("\n***************** ��ѡ����Ҫ�޸ĵ���Ŀ *****************\n");
        printf(" A: ����       B: �Ա�       C: ѧ��       D: ��У״̬\n");
        printf(" E: �꼶       F: ���       G: ���ĳɼ�    H��Ӣ��ɼ�\n");
        printf(" I: ��ѧ�ɼ�    J:�޸�������Ϣ              0: �˳��޸�\n");
        printf("******************************************************\n");
        scanf("%c", &ch);
        getchar();
        }
Enter:  printf("��������Ҫ����/�޸�ѧ����ѧ��(����0�˳�)��");
        scanf("%ld", &id);
        getchar();
    }


}


// ģ���ģ���ʾ��Ϣ
/********************************* ��ʾ����ѧ������ *********************************/  
void print()           
{  
    Student * p;                            // �ƶ����
    printf("There are %5d datas:\n",n);
    printf("Name  student_id  continue_drop  gender  grade  class  chinese_marks  english_marks  math_marks\n");
    p = head;                               // �ƶ����ָ��ͷ���
    if (p != NULL)                          // �������ǿ�
    {
        do
        {  
            /* Ϊ�˴�ӡ���룬����������������������ֽ������֣���ʱ�������������֣�ͬʱ���ٽ� 0�� 1ת��Ϊyes or no */
            
            if (p->name[5] != '\0')         // ��������
            {
                printf("%4s %8ld", p->name, p->student_id);
                p->continue_drop?printf("       YES"):printf("       NO ");
                p->gender?printf("         MALE  "):printf("        FEMALE ");
                printf("%5d %5d %11.2f %15.2f %12.2f", p->grade, p->class, p->chinese_marks, p->english_marks, p->math_marks);
                printf("\n");
            }
            else                            // ��������
            {
                printf("%4s %10ld", p->name,p->student_id);
                p->continue_drop?printf("       YES"):printf("       NO ");
                p->gender?printf("         MALE  "):printf("        FEMALE ");
                printf("%5d %5d %11.2f %15.2f %12.2f", p->grade, p->class, p->chinese_marks, p->english_marks, p->math_marks);
                printf("\n");
            }
            p = p->next;                    // �ƶ����ָ����һ�����
        }while (p != NULL);                 // δ�ﵽ����β�������ӡ
    }
    else                                    // ���Ϊ������
        printf("The student was not found!\n");
}

/******************************* ��ӡ����ѧ����Ϣ���� ********************************/ 
void print_personal(Student * p)
{
    printf("Student ID: %ld\n", p->student_id);
    printf("Name: %s\n", p->name);
    // �ж��Ա�
    if (p->gender == 0)
        printf("Gender: male\n");
    else
        printf("Gender: female\n");
    printf("Class: class%d grade%d\n", p->class, p->grade);
    // �ж��ڶ�״̬
    if (p->continue_drop == 0)
        printf("Whether the student is in school: NO\n");
    else
        printf("Whether the student is in school: YES\n");
    // �ɼ�
    printf("Chinese score: %.2f\n", p->chinese_marks);
    printf("Math score: %.2f\n", p->math_marks);
    printf("English score: %.2f\n", p->english_marks);
}

/******************************* ��ӡ�����༶ѧ������ ********************************/ 
void print_class()
{
    Student * p;
    int grade;
    int class;
    printf("Enter the class:(grade,class)  ");
    scanf("%d,%d", &grade,&class);
    getchar();
    p= head;
    printf("\n\t\t****************** Class %d Grade %d ******************\n", class, grade);
    printf("Name  student_id  continue_drop  gender  grade  class  chinese_marks  english_marks  math_marks\n");
    if (p != NULL)
    {
        do
        {  
            // ��������Ҫ��ӡ�İ༶֮��ʱ��ֱ���˳�
            // if (p->grade > grade || p->class > class)   
            //     break;       (���������������У������bug�����ǰ��ͬʱ�޸Ĺ�ѧ����ѧ�ţ������������ܵ���
            // �༶���꼶�������������򣬹���Ҫ������������������ֻ����ǰ�벿��)

            if (p->grade == grade && p->class == class)            // ������������
            {
                /* Ϊ�˴�ӡ���룬����������������������ֽ������֣���ʱ�������������֣�ͬʱ���ٽ� 0�� 1ת��Ϊyes or no */
                
                if (p->name[5] != '\0')         // ��������
                {
                    printf("%4s %8ld", p->name, p->student_id);
                    p->continue_drop?printf("       YES"):printf("       NO ");
                    p->gender?printf("         MALE  "):printf("        FEMALE ");
                    printf("%5d %5d %11.2f %15.2f %12.2f", p->grade, p->class, p->chinese_marks, p->english_marks, p->math_marks);
                    printf("\n");
                }
                else                            // ��������
                {
                    printf("%4s %10ld", p->name,p->student_id);
                    p->continue_drop?printf("       YES"):printf("       NO ");
                    p->gender?printf("         MALE  "):printf("        FEMALE ");
                    printf("%5d %5d %11.2f %15.2f %12.2f", p->grade, p->class, p->chinese_marks, p->english_marks, p->math_marks);
                    printf("\n");
                }
            }
            p = p->next;                        // �ƶ����ָ����һ�����
        }while (p != NULL);                     // δ�ﵽ����β�������ӡ
    }
    else                                        // ���Ϊ������
        printf("Error!\n");
}

/******************************* ��ӡ�����꼶ѧ������ ********************************/ 
void print_grade()
{
    Student * p;
    int grade;
    printf("Enter the grade:");
    scanf("%d", &grade);
    getchar();
    p= head;
    printf("\n\t\t********************** Grade %d **********************\n", grade);
    printf("Name  student_id  continue_drop  gender  grade  class  chinese_marks  english_marks  math_marks\n");
    if (p != NULL)                          // �ǿ�����
    {
        do
        {  
            // if (p->grade > grade)        // ���õ�ԭ��ͬ print_class
            //     break;
            if (p->grade == grade)
            {
                /* Ϊ�˴�ӡ���룬����������������������ֽ������֣���ʱ�������������֣�ͬʱ���ٽ� 0�� 1ת��Ϊyes or no */
                
                if (p->name[5] != '\0')     // ��������
                {
                    printf("%4s %8ld", p->name, p->student_id);
                    p->continue_drop?printf("       YES"):printf("       NO ");
                    p->gender?printf("         MALE  "):printf("        FEMALE ");
                    printf("%5d %5d %11.2f %15.2f %12.2f", p->grade, p->class, p->chinese_marks, p->english_marks, p->math_marks);
                    printf("\n");
                }
                else                        // ��������
                {
                    printf("%4s %10ld", p->name,p->student_id);
                    p->continue_drop?printf("       YES"):printf("       NO ");
                    p->gender?printf("         MALE  "):printf("        FEMALE ");
                    printf("%5d %5d %11.2f %15.2f %12.2f", p->grade, p->class, p->chinese_marks, p->english_marks, p->math_marks);
                    printf("\n");
                }
            }
            p = p->next;                    // �ƶ����ָ����һ�����
        }while (p != NULL);                 // δ�ﵽ����β�������ӡ
    }
    else                                    // ���Ϊ������
        printf("Error!\n");
}



/************************************ �û��ӿ� *************************************/
void user()
{
    char choose;             // �洢�û�ѡ��
    char choose_a, choose_b;
    char *filename;

    printf("******************** ѡ���� ********************\n");
    printf("   A: ��ʾѧ����Ϣ    B: ����ѧ��    C: ���ѧ��    \n");
    printf("   D: �޸�ѧ����Ϣ    E: ɾ��ѧ��    F: ��ȡ����    \n");
    printf("   0���˳�����\n");
    printf("**************************************************\n");
    scanf("%c", &choose);
    getchar();
    while (choose != '0')
    {
        switch (choose)
        {
        case 'A':
            printf("\na: ��ʾ����ѧ��  b����ʾ�༶   c:��ʾ�꼶\nEnter:");
            scanf("%c", &choose_a);
            getchar();
            switch (choose_a)
            {
                case 'a': print(); 
                    break;
                case 'b': print_class();
                    break;
                case 'c': print_grade();
                    break;
                default:
                    break;
            }
            break;
        case 'B':
            seek();
            break;
        case 'C':
            add();
            break;
        case 'D':
            change();
            break;
        case 'E':
            clear();
            break;
        case 'F':
            printf("a: ����(Ĭ��textdata_save.csv)     b:���Ϊ(���ļ�)\nEnter:");
            scanf("%c", &choose_b);
            getchar();
            switch (choose_b)
            {
                case 'a':
                    write_file("textdata_save.csv");
                    break;
                case 'b':
                    printf("Enter new file name:");
                    scanf("%s", filename);
                    getchar();
                    write_file(filename);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
        }
        printf("******************** ѡ���� ********************\n");
        printf("   A: ��ʾѧ����Ϣ    B: ����ѧ��    C: ���ѧ��    \n");
        printf("   D: �޸�ѧ����Ϣ    E: ɾ��ѧ��    F: ��ȡ����    \n");
        printf("   0���˳�����\n");
        printf("**************************************************\n");
        scanf("%c", &choose);
        getchar();
    }
}

/////////////////////////////////////////////////////////////////////////////////////
/************************************** ������  *************************************/
/////////////////////////////////////////////////////////////////////////////////////
int main()
{
    char * filename = "student_data.csv";       // �ļ���
    read_file(filename);                        // �����ļ�
    user(head);                                 // �û��ӿ�
    disposal_LinkList(head);                    // �ͷ��ڴ�
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////