#include "lib.h"

char fname[] = __FILE__;
char PATH_IN[__CHAR_BUFFER] = "../../Resource/";
char PATH_OUT[__CHAR_BUFFER] = "../../Release/";

int main(int argc, char* argv[])
{
  // fpath(a, b, a2);
  path(fname, PATH_IN, PATH_OUT);    //?·��
  init_N(fin2);                      //?��ʼ��N
  init_str_M(c, __CHAR_BUFFER, fin); //?��ȡǰ�ö����Լ���ʼ��M
  int** tt = init_data(N, M + 1);    //*�������ݿ�
  input_data(fin, tt);               //?��ȡ����
  adjust_data(tt);                   //?��������
  output_data(fout, tt);             //!����ļ�
  path2(PATH_OUT);
  adjust_csv(fout, tt);
  return 0;
}
void adjust_csv(FILE* fout, int** tt)
{
  char csv[N][4][__CHAR_BUFFER];
  char sts[35][__CHAR_BUFFER];
  strcpy(sts[0], "����״̬_");
  strcpy(sts[1], "���ڻ�����趨�߶�_");
  strcpy(sts[2], "���ڹ���_");
  strcpy(sts[3], "���ڿ���_");
  strcpy(sts[4], "ֹͣ״̬_");
  strcpy(sts[5], "����������_");
  strcpy(sts[6], "��������_");
  strcpy(sts[7], "���ڽ���_");
  strcpy(sts[8], "����ǿ����_");
  strcpy(sts[22], "���ڹ���_");
  strcpy(sts[33], "���ڿ���_");

  char bcm[8][__CHAR_BUFFER];
  strcpy(bcm[0], "DEFAULT/OFF/ACC/START/INVAILD״̬_");
  strcpy(bcm[1], "DEFAULT/OFF/ACC/START/INVAILD״̬_");
  strcpy(bcm[2], "DEFAULT/OFF/ACC/START/INVAILD״̬_");
  strcpy(bcm[3], "ON״̬_");
  strcpy(bcm[4], "DEFAULT/OFF/ACC/START/INVAILD״̬_");
  strcpy(bcm[5], "invalid_valid״̬_");
  strcpy(bcm[6], "invalid_valid״̬_");
  strcpy(bcm[7], "DEFAULT/OFF/ACC/START/INVAILD״̬_");

  char speed_valid[2][40];
  strcpy(speed_valid[0], "�ٶ���Ч��");
  strcpy(speed_valid[1], "�ٶ���Ч��");

  char speed[101][40];
  strcpy(speed[0], "\t0km/h");
  strcpy(speed[2], "\tС��5km/h");
  strcpy(speed[5], "\t5km/h");
  strcpy(speed[100], "����5km/h");

  char ctrl[45][40];
  strcpy(ctrl[1], "��������");
  strcpy(ctrl[2], "�����ر�");
  strcpy(ctrl[12], "Զ�̹ر�");
  strcpy(ctrl[13], "Զ��С�Ƕ�");
  strcpy(ctrl[21], "�����ر�");
  strcpy(ctrl[22], "��������");
  strcpy(ctrl[23], "����ֹͣ");
  strcpy(ctrl[31], "�����ⲿ����");
  strcpy(ctrl[33], "����Կ�׶̰�");
  strcpy(ctrl[34], "�����ź�");
  strcpy(ctrl[36], "һ��Կ�׶̰�");
  strcpy(ctrl[40], "���Ŷ̰�");
  strcpy(ctrl[41], "���ų���");
  strcpy(ctrl[42], "���ų�����");

  char target[10][100];
  strcpy(target[1], "��������");
  strcpy(target[2], "�����ر�");

  for (i = 0; i < N; i++)
  {
    int a = tt[i][0]; // sts
    int b = tt[i][1]; // bcm
    int c = tt[i][2]; // speedvalid
    int d = tt[i][3]; // speed
    int e = tt[i][4]; // ctrl
    int f = tt[i][5]; // target

    // Excel��һ��
    strcpy(csv[i][0], sts[a]);
    strcat_s(csv[i][0], bcm[b]);
    strcat_s(csv[i][0], ctrl[e]);
    // Excel�ڶ���
    strcat_s(csv[i][1], speed_valid[c]);
    strcat_s(csv[i][1], speed[d]);
    strcat_s(csv[i][1],
             "\n��������������ѹ��Χ\n�޴��󹤿������ȱ�����ͨѶ���ϵȣ�");
    // Excel������
    strcpy(csv[i][2], "����");
    strcat_s(csv[i][2], ctrl[e]);
    strcat_s(csv[i][2], "�ź�");
    // Excel���ĸ�  ����
    // strcat_s(csv[i][1], "\"");
    // strcat_s(csv[i][1], speed_valid[c]);
    // strcat_s(csv[i][1], speed[d]);

    fprintf_s(fout, "%s,\"%s\",%s,", csv[i][0], csv[i][1], csv[i][2]);

    if (1)
    {
      fprintf_s(fout, "β�Ų���Ӧ����ָ��\n");
    }
  }
}
void adjust_data(int** A)
{
  for (i = 0; i < N; i++)
  {
    if (A[i][4] == 33)
    {
      A[i][4] = 36;
    }
  }
  for (i = 0; i < N; i++)
  {
    // if (A[i][1] == 0 || A[i][1] == 1 || A[i][1] == 7 || A[i][1] == 2 ||
    //     A[i][1] == 4 || (A[i][1] == 3 && A[i][3] < 5 && A[i][2] == 1)) {
    //   A[i][M] = 4;
    if (A[i][0] == 22)
    {
      A[i][M] = 0;
    }
    else
      A[i][M] = 1;
  }
}
