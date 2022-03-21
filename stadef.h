/***********************************************************************************/
/*********************************** �����붨�� *************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define LEN sizeof(struct Student)     // ����С
// ȫ�ֱ���
int n = 0;                             // ������������������
typedef struct Student                 // ��������
{
    char name[7];                      // ����
    int continue_drop;                 // �Ƿ��ڶ���1�ǣ�0��
    long student_id;                   // ѧ��
    int gender;                        // �Ա�1�У�0Ů��
    int grade;                         // �꼶
    int class;                         // ���
    float chinese_marks;               // ���ĳɼ�
    float english_marks;               // Ӣ��ɼ�
    float math_marks;                  // ��ѧ�ɼ�
    struct Student * next;             // ָ����
}Student;                              // ������
Student * head;                        // ����ͷָ��

// ��������
void add();                                          // ���ѧ��
void sort();                                         // ����ѧ������
void seek();                                         // ����ѧ��
void user();                                         // �û�ʹ�ýӿ�
void clear();                                        // ɾ��ѧ��
void print();                                        // �����ӡ
void change();                                       // �޸�ѧ����Ϣ
void print_class();                                  // ��ӡ�����༶ѧ����Ϣ
void print_grade();                                  // ��ӡ�����꼶ѧ����Ϣ
void insert(Student * stud);                         // ���������
void read_file(char * file_name);                    // ��ȡ�ļ�
void write_file(char * filename);                    // д���ļ�����
void print_personal(Student * p);                    // ��ӡ����ѧ����Ϣ
void disposal_LinkList(Student * headNode);          // �ͷ�����
void data_input(Student * p1, char * data_row);      // �洢�ļ�����
/***********************************************************************************/
/***********************************************************************************/