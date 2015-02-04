// TwoD: 2-dimensional dynamic array of doubles
namespace twodimarray{

class TwoD{
 public:
  TwoD();
  TwoD(int maxNumberRows, int maxNumberCols);
  TwoD(const TwoD& source); // copy constructor
  ~TwoD();
  TwoD& operator=(const TwoD& source);
  void setEntry(int row, int column, int value);
  double getEntry(int row, int column) const;
  friend const TwoD operator+(const TwoD& matrix1, const TwoD& matrix2);
  void print() const;
 private:
  double** dynArray;
  int maxRows;
  int maxCols;

};

} // namespace twodimarray
