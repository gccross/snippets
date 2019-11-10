#include <numeric>
#include <iostream>
using namespace std;


template <typename T>
class row_iterator
{
	public:
		row_iterator(T* _p, const size_t _ncols) : p(_p), ncols(_ncols){};
		size_t num_cols(){ return ncols; };
		row_iterator& operator++ () { p+=ncols; return *this; };
		row_iterator operator++ (int) { row_iterator temp(*this); operator++(); return temp; };
		row_iterator operator+(int distance) const { row_iterator temp(*this); temp.p += distance*ncols; return temp; };

		T& operator*() { return *p; };
		template <class R> friend bool operator!=(row_iterator<R>, row_iterator<R>);
	private:
		T* p;
		size_t ncols;

};

template <typename T> 
bool operator!=(row_iterator<T> left, row_iterator<T> right) { return left.p != right.p; };

class Point_Getter
{
	public:
		Point_Getter(row_iterator<int> const _rit, size_t const _ncols): rit(_rit), ncols(_ncols) {};
		int get_pts(int* m, size_t row_index, size_t col_index)
		{
			int pts = 0;
			if (0==row_index)
				if (0==col_index)
					return 0;
				else 
					return accumulate(m,m+col_index+1, 0);
			else if (0==col_index)
				if (0==row_index)
					return 0;
				else return accumulate(rit,rit+row_index+1, 0);

			else 
				pts = m[row_index*ncols + col_index+ 1] + min(get_pts(m, row_index-1, col_index), get_pts(m, row_index, col_index-1));

			if (pts<=0) pts = numeric_limits<int>::max();
			return pts;

		} 
	private:
		row_iterator<int> const rit;
		size_t const ncols;
};

int main() {
	unsigned T, R, C;

	cin >> T;
	while (T--)
	{
		cin >> R >> C;
		int m[R*C];
		row_iterator<int> rit(m, C);
		for (size_t row = 0; row < R; ++row)
			for (size_t col=0; col < C; ++col)
				cin >> m[(row*C)+ col];
		Point_Getter pg(rit, C);
		pg.get_pts(m, R-1, C-1);
		for (size_t row = 0; row < R; ++row) {
			for (size_t col=0; col < C; ++col)
				cout << m[(row*C) + col] << '\t';
			cout << endl;
		}
	}
	//code
	return 0;
}
