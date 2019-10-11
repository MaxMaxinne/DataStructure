template<class T>
class LinearList {
public:
	virtual bool empty()const = 0;
	virtual int getSize() const = 0;
	virtual T& get(int index) const= 0;
	virtual int indexof(const T& element) const= 0;
	virtual void erase(int index) = 0;
	virtual void insert(int index, T& element) = 0;
};
