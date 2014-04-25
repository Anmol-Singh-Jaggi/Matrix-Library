#include<bits/stdc++.h>
using namespace std;

// Class Definition begins...
template<typename T>
class matrix
{
    // Member Data types
    int rows,cols;
    vector<vector<T> > matrix_data;

    // Friend function declarations for binary relational operators...
    friend bool operator == <T>(const matrix<T>& lhs,const matrix<T>& rhs);
    friend bool operator != <T>(const matrix& lhs,const matrix& rhs);
    friend bool operator < <T>(const matrix& lhs,const matrix& rhs);
    friend bool operator > <T>(const matrix& lhs,const matrix& rhs);
    friend bool operator <= <T>(const matrix& lhs,const matrix& rhs);
    friend bool operator >= <T>(const matrix& lhs,const matrix& rhs);

public:
    matrix(const int& row=1,const int& col=1)  // Constructor
    {
        matrix_data.resize(row,vector<int> (col,-1));
        this->rows=row;
        this->cols=col;
    }

    // Binary Arithmetic Operators modifying the LHS...
    matrix& operator +=(const matrix& rhs)
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

    matrix& operator -=(const matrix& rhs)
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

    matrix& operator *=(const matrix& rhs)
    {
        assert(this->cols==rhs.rows);
        matrix result(this->rows,rhs.cols);
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
        return (*this=result);
    }

    vector<int>& operator [](const int &pos)  // Array Subscription Operator...
    {
        return this->matrix_data[pos];
    }

    const vector<int>& operator [](const int &pos) const  // Array Subscription Operator [ const version ]...
    {
        return this->matrix_data[pos];
    }

    int row_count() const  // Get rows...
    {
        return rows;
    }

    int col_count() const  // Get columns...
    {
        return cols;
    }
};


// Binary Relational Operators Definitions...
template<typename T>
inline bool operator ==(const matrix<T>& lhs,const matrix<T>& rhs)  // Binary relational operator actually implemented on its own..
{
    return lhs.matrix_data==rhs.matrix_data;
}

template<typename T>
inline bool operator !=(const matrix<T>& lhs,const matrix<T>& rhs)  // Dependent on "=="...
{
    return !(lhs==rhs);
}

template<typename T>
inline bool operator <(const matrix<T>& lhs,const matrix<T>& rhs)  // Binary relational operator actually implemented on its own..
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
inline matrix<T> operator +(matrix<T> lhs,const matrix<T>& rhs)
{
    lhs+=rhs;
    return lhs;
}

template<typename T>
inline matrix<T> operator -(matrix<T> lhs,const matrix<T>& rhs)
{
    lhs-=rhs;
    return lhs;
}

template<typename T>
inline matrix<T> operator *(matrix<T> lhs,const matrix<T>& rhs)
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
            in>>m[i][j];
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
            out<<m[i][j]<<" ";
        }
        out<<"\n";
    }
    return out;
}

// Class Definition ends...

int main()
{

}
