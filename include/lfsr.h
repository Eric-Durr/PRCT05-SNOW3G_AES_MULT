
#ifndef LFSR_H_
#define LFSR_H_
#include <vector>
#include <string>
#include <set>

template <class T>
class LFSR
{
private:
  int length_;
  std::vector<T> lfsr_set_;
  std::set<int> taps_;

public:
  LFSR(const int &length = 1, const std::set<int> &taps = {});
  ~LFSR();

  const T &at(int pos) const { return lfsr_set_[pos]; };
  T &at(int pos) { return lfsr_set_[pos]; };

  const int &length(void) const { return length_; }
  // void length(int length) { length_ = length; }

  const std::set<int> &taps(void) const { return taps_; }

  std::string to_string(void) const;

  T step(void);
  // std::vector<T> generate(int steps);

private:
  void rotate(const T &new_element);
};

template <class T>
LFSR<T>::LFSR(const int &length, const std::set<int> &taps) : length_(length), taps_(taps)
{
  for (int i = 0; i < this->length_; ++i)
    this->lfsr_set_.push_back(1);
}

template <class T>
LFSR<T>::~LFSR() {}

template <class T>
std::string LFSR<T>::to_string(void) const
{
  std::string output = "[ ";
  for (auto element : lfsr_set_)
    output += std::to_string(element) + " ";
  return output += "]";
}

template <class T>
T LFSR<T>::step(void)
{
  T last = this->at(this->length_ - 1);

  return last;
}

template <class T>
void LFSR<T>::rotate(const T &new_element)
{
}

#endif /* LFSR_H_ */