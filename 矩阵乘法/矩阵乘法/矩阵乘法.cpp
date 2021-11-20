#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> creatematrix(vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            printf("[%d][%d]=", i, j);
            cin >> mat[i][j];
        }
    }
    cout << endl;
    return mat;
}

vector<vector<int>> multimatrix(vector<vector<int>> mat1, vector<vector<int>> mat2, vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            for (int n = 0; n < mat2.size(); n++)
            {
                mat[i][j] += mat1[i][n] * mat2[n][j];
            }
        }
    }
    return mat;
}

void outputmatrix(vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

int main()
{
    while (true)
    {
        int m1 = 1, n1 = 1, m2 = 1, n2 = 1;
        cout << "第一个矩阵的行数:";
        cin >> n1;
        cout << "列数:";
        cin >> m1;
        cout << "第二个矩阵的行数:";
        cin >> n2;
        cout << "列数:";
        cin >> m2;
        if (n1 != m2 || m1 * n1 * m2 * n2 == 0)
        {
            cout << "矩阵相乘的条件：行数等于列数。";
            return 0;
        }
        int m = n1, n = n1;

        vector<vector<int> > mat(n);
        for (int i = 0; i < mat.size(); i++)
        {
            mat[i].resize(m);
        }
        vector<vector<int> > mat1(n1);
        for (int i = 0; i < mat1.size(); i++)
        {
            mat1[i].resize(m1);
        }
        vector<vector<int> > mat2(n2);
        for (int i = 0; i < mat2.size(); i++)
        {
            mat2[i].resize(m2);
        }

        mat1 = creatematrix(mat1);
        mat2 = creatematrix(mat2);
        mat = multimatrix(mat1, mat2, mat);
        outputmatrix(mat1);
        outputmatrix(mat2);
        outputmatrix(mat);
    }
}