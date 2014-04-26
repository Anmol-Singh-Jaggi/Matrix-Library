#include<bits/stdc++.h>
using namespace std;


// MATRIX BEGINS...

// Class Forward Declaration...
template<typename T>
class matrix;

//  Declarations for Friend Functions...
template<typename T> bool operator == (const matrix<T>& lhs,const matrix<T>& rhs);
template<typename T> bool operator != (const matrix<T>& lhs,const matrix<T>& rhs);
template<typename T> bool operator < (const matrix<T>& lhs,const matrix<T>& rhs);
template<typename T> bool operator > (const matrix<T>& lhs,const matrix<T>& rhs);
template<typename T> bool operator <= (const matrix<T>& lhs,const matrix<T>& rhs);
template<typename T> bool operator >= (const matrix<T>& lhs,const matrix<T>& rhs);

template<typename T>
class matrix
{
    // Member Data types
    int rows,cols;
    vector<vector<T> > matrix_data;

    // Friend function declarations for binary relational operators...
    friend bool operator == <>(const matrix& lhs,const matrix& rhs);
    friend bool operator != <>(const matrix& lhs,const matrix& rhs);
    friend bool operator < <>(const matrix& lhs,const matrix& rhs);
    friend bool operator > <>(const matrix& lhs,const matrix& rhs);
    friend bool operator <= <>(const matrix& lhs,const matrix& rhs);
    friend bool operator >= <>(const matrix& lhs,const matrix& rhs);

public:

    // Constrcutor...
    matrix(const int& row,const int& col,const T& value);

    // Binary Arithmetic Operators modifying the LHS...
    matrix& operator +=(const matrix& rhs);
    matrix& operator -=(const matrix& rhs);
    matrix& operator *=(const matrix& rhs);

    // Array Subscription Operator...
    vector<T>& operator [](const int &pos);
    const vector<T>& operator [](const int &pos) const;

    // Getters...
    int row_count() const;  // Get rows...
    int col_count() const;  // Get columns...
};


// Class member Function Definitions...
template<typename T>
matrix<T>::matrix(const int& row=1,const int& col=1,const T& value=0)
{
    matrix_data.resize(row,vector<T> (col,value));
    this->rows=row;
    this->cols=col;
}

template<typename T>
matrix<T>& matrix<T>::operator +=(const matrix<T>& rhs)
{
    assert(this->rows==rhs.rows&&this->cols==rhs.cols);
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            this->matrix_data[i][j]+=rhs.matrix_data[i][j];
        }
    }
    return *this;
}

template<typename T>
matrix<T>& matrix<T>::operator -=(const matrix<T>& rhs)
{
    assert(this->rows==rhs.rows&&this->cols==rhs.cols);
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            this->matrix_data[i][j]-=rhs.matrix_data[i][j];
        }
    }
    return *this;
}

template<typename T>
matrix<T>& matrix<T>::operator *=(const matrix<T>& rhs)
{
    assert(this->cols==rhs.rows);
    matrix<T> result(this->rows,rhs.cols);
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<rhs.cols; j++)
        {
            for(int k=0; k<rhs.rows; k++)
            {
                result[i][j]+=this->matrix_data[i][k]*rhs.matrix_data[k][j];
            }
        }
    }
    this->cols=rhs.cols;
    return (*this=result);
}

template<typename T>
vector<T>& matrix<T>::operator [](const int &pos)
{
    return this->matrix_data[pos];
}

template<typename T>
const vector<T>& matrix<T>::operator [](const int &pos) const
{
    return this->matrix_data[pos];
}

template<typename T>
int matrix<T>::row_count() const
{
    return rows;
}

template<typename T>
int matrix<T>::col_count() const
{

    return cols;
}


// Binary Relational Operators Definitions...
template<typename T>
inline bool operator ==(const matrix<T>& lhs,const matrix<T>& rhs)   // Calls "==" operator of vector<T>...
{
    return lhs.matrix_data==rhs.matrix_data;
}

template<typename T>
inline bool operator !=(const matrix<T>& lhs,const matrix<T>& rhs)  // Dependent on "=="...
{
    return !(lhs==rhs);
}

template<typename T>
inline bool operator <(const matrix<T>& lhs,const matrix<T>& rhs)  // Calls "<" operator of vector<T>...
{
    return lhs.matrix_data<rhs.matrix_data;
}

template<typename T>
inline bool operator >(const matrix<T>& lhs,const matrix<T>& rhs)  // Dependent on "<"...
{
    return rhs<lhs;
}

template<typename T>
inline bool operator <=(const matrix<T>& lhs,const matrix<T>& rhs)  // Dependent on ">"...
{
    return !(lhs>rhs);
}

template<typename T>
inline bool operator >=(const matrix<T>& lhs,const matrix<T>& rhs)  // Dependent on "<"...
{
    return !(lhs<rhs);
}

// Binary Arithmetic Operators not modifying the LHS...
template<typename T>
inline matrix<T> operator +(matrix<T> lhs,const matrix<T>& rhs)  // Dependent on "+="...
{
    lhs+=rhs;
    return lhs;
}

template<typename T>
inline matrix<T> operator -(matrix<T> lhs,const matrix<T>& rhs)  // // Dependent on "-="...
{
    lhs-=rhs;
    return lhs;
}

template<typename T>
inline matrix<T> operator *(matrix<T> lhs,const matrix<T>& rhs)  // // Dependent on "*="...
{
    lhs*=rhs;
    return lhs;
}

// I/O Operators...
template<typename T>
istream& operator>>(istream &in,matrix<T> &m)
{
    for(int i=0; i<m.row_count(); i++)
    {
        for(int j=0; j<m.col_count(); j++)
        {
            in>>m[i][j];  // ">>" operator for "T" must be defined...
        }
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream &out,const matrix<T> &m)
{
    for(int i=0; i<m.row_count(); i++)
    {
        for(int j=0; j<m.col_count(); j++)
        {
            out<<m[i][j]<<" ";   // "<<" operator for "T" must be defined...
        }
        out<<"\n";
    }
    return out;
}

// MATRIX ENDS...

// Usage..
int main()
{
    matrix<double> a(5,5,0.1),b(5,5,2);
    cout<<a+b;
}
