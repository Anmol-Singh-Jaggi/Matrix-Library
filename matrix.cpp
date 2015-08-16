#include<iostream>
#include<cassert>
#include<vector>
#include<stdexcept>
using namespace std;

// MATRIX BEGINS

// Class forward declaration
template<typename T>
class Matrix;

// Declarations for friend functions
template<typename T> bool operator == ( const Matrix<T>& first, const Matrix<T>& second );
template<typename T> bool operator != ( const Matrix<T>& first, const Matrix<T>& second );
template<typename T> bool operator < ( const Matrix<T>& first, const Matrix<T>& second );
template<typename T> bool operator > ( const Matrix<T>& first, const Matrix<T>& second );
template<typename T> bool operator <= ( const Matrix<T>& first, const Matrix<T>& second );
template<typename T> bool operator >= ( const Matrix<T>& first, const Matrix<T>& second );

template<typename T>
class Matrix
{
	// Class data members
	size_t rows, columns;
	vector<vector<T> > data;

	// Friend function declarations for binary relational operators
	friend bool operator == <>( const Matrix& first, const Matrix& second );
	friend bool operator != <>( const Matrix& first, const Matrix& second );
	friend bool operator < <>( const Matrix& first, const Matrix& second );
	friend bool operator > <>( const Matrix& first, const Matrix& second );
	friend bool operator <= <>( const Matrix& first, const Matrix& second );
	friend bool operator >= <>( const Matrix& first, const Matrix& second );

public:

	// Constructor
	Matrix( const size_t& _rows, const size_t& _columns, const T& value );

	// Binary arithmetic operators modifying the LHS
	Matrix& operator +=( const Matrix& second );
	Matrix& operator -=( const Matrix& second );
	Matrix& operator *=( const Matrix& second );

	// Array subscription operator
	vector<T>& operator []( const size_t& pos );
	const vector<T>& operator []( const size_t& pos ) const;

	// Getters
	size_t GetRows() const;  // Get rows
	size_t GetColumns() const;  // Get columns
};


// Class member function definitions
template<typename T>
Matrix<T>::Matrix( const size_t& _rows, const size_t& _columns, const T& value )
{
	if ( _rows == 0 || _columns == 0 )
	{
		throw invalid_argument( "The dimensions of the matrix cannot be zero!" );
	}

	this->rows = _rows;
	this->columns = _columns;
	data.resize( this->rows, vector<T> ( this->columns, value ) );
}

template<typename T>
Matrix<T>& Matrix<T>::operator +=( const Matrix<T>& second )
{
	if ( this->rows != second.rows || this->columns != second.columns )
	{
		throw domain_error( "Dimensions incompatible for the operation '+='!" );
	}

	for ( size_t i = 0; i < rows; i++ )
	{
		for ( size_t j = 0; j < columns; j++ )
		{
			this->data[i][j] += second.data[i][j];
		}
	}

	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator -=( const Matrix<T>& second )
{
	if ( this->rows != second.rows || this->columns != second.columns )
	{
		throw domain_error( "Dimensions incompatible for the operation '-='!" );
	}

	for ( size_t i = 0; i < rows; i++ )
	{
		for ( size_t j = 0; j < columns; j++ )
		{
			this->data[i][j] -= second.data[i][j];
		}
	}

	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator *=( const Matrix<T>& second )
{
	if ( this->columns != second.rows )
	{
		throw domain_error( "Dimensions incompatible for the operation '*='!" );
	}

	Matrix<T> result( this->rows, second.columns );

	for ( size_t i = 0; i < rows; i++ )
	{
		for ( size_t j = 0; j < second.columns; j++ )
		{
			for ( size_t k = 0; k < second.rows; k++ )
			{
				result[i][j] += this->data[i][k] * second.data[k][j];
			}
		}
	}

	this->columns = second.columns;

	return ( *this = result );
}

template<typename T>
vector<T>& Matrix<T>::operator []( const size_t& pos )
{
	return this->data[pos];
}

template<typename T>
const vector<T>& Matrix<T>::operator []( const size_t& pos ) const
{
	return this->data[pos];
}

template<typename T>
size_t Matrix<T>::GetRows() const
{
	return rows;
}

template<typename T>
size_t Matrix<T>::GetColumns() const
{
	return columns;
}


// Binary relational operators definitions

template<typename T>
bool operator ==( const Matrix<T>& first, const Matrix<T>& second )
{
	return first.data == second.data;
}

template<typename T>
bool operator !=( const Matrix<T>& first, const Matrix<T>& second )
{
	return !( first == second );
}

template<typename T>
bool operator <( const Matrix<T>& first, const Matrix<T>& second )
{
	return first.data < second.data;
}

template<typename T>
bool operator >( const Matrix<T>& first, const Matrix<T>& second )
{
	return second < first;
}

template<typename T>
bool operator <=( const Matrix<T>& first, const Matrix<T>& second )
{
	return !( first > second );
}

template<typename T>
bool operator >=( const Matrix<T>& first, const Matrix<T>& second )
{
	return !( first < second );
}

// Binary arithmetic operators not modifying the LHS
template<typename T>
Matrix<T> operator +( Matrix<T> first, const Matrix<T>& second )
{
	first += second;
	return first;
}

template<typename T>
Matrix<T> operator -( Matrix<T> first, const Matrix<T>& second )
{
	first -= second;
	return first;
}

template<typename T>
Matrix<T> operator *( Matrix<T> first, const Matrix<T>& second )
{
	first *= second;
	return first;
}

// I/O operators
template<typename T>
istream& operator>>( istream& in, Matrix<T>& matrix )
{
	for ( size_t i = 0; i < matrix.GetRows(); i++ )
	{
		for ( size_t j = 0; j < matrix.GetColumns(); j++ )
		{
			in >> matrix[i][j];
		}
	}

	return in;
}

template<typename T>
ostream& operator<<( ostream& out, const Matrix<T>& matrix )
{
	for ( size_t i = 0; i < matrix.GetRows(); i++ )
	{
		for ( size_t j = 0; j < matrix.GetColumns(); j++ )
		{
			out << matrix[i][j] << " ";
		}
		out << "\n";
	}

	return out;
}

// MATRIX ENDS

// Usage
int main()
{
	Matrix<double> matrix1( 5, 5, 0.1 );
	Matrix<double> matrix2( 5, 5, 2 );

	Matrix<double> matrix3 = matrix1 + matrix2;
	cout << matrix3;
}
