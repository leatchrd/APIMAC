
#include <iostream>
#include <stdexcept>

template<typename T, size_t N>
class Tableau{
	

	private : 
		T m_data[N];
		size_t m_size;

	public :
		Tableau() : m_size(0) {
			for(size_t i=0; i<N; ++i)
				m_data[i] = T(0);
		}	

	bool isEmpty() const noexcept {return m_size == 0;}

	size_t getSize() const noexcept {return m_size;}

	size_t getMaxSize() const {return N;}

	T &getFirst() {
		if (isEmpty()) throw std::underflow_error("Error: Tableau is empty");
		else return m_data[0];
	}

	T &getLast() {
		if (isEmpty()) throw std::underflow_error("Error: Tableau is empty");
		else return m_data[m_size - 1];
	}

	T &operator[](const size_t i) noexcept {
		return m_data[i];
	}

	const T &operator[](const size_t i) const noexcept {
		return m_data[i];
	}

	T &at(const size_t i)
	{
		if (i >= m_size) throw std::out_of_range("Error: index out of range");
		return m_data[i];
	}

	void push(const T &val) {
		if (m_size >= N) throw std::overflow_error("Error: max size reached");
		m_data[m_size] = val;
		++m_size;
	}

	T pop() {
		if (m_size <= 0) throw std::underflow_error("Error: Tableau is empty");
		--m_size;
		return m_data[m_size];
	}

	void insert(const T &d, const size_t i)
	{
		if (i < 0 || i >= m_size)
			throw std::out_of_range("Error: index out of range");
		if (m_size >= N)
			throw std::overflow_error("Error: max size reached");

		for(size_t c=m_size; c>i; --c)
			m_data[c] = m_data[c - 1];

		m_data[i] = d;
		++m_size;
	}


	void erase(const size_t i)
	{
		if (i < 0 || i >= m_size) throw std::out_of_range("Error: index out of range");

		for (size_t c = i; c < m_size - 1; ++c)
			m_data[c] = m_data[c + 1];

		--m_size;
	}


	friend std::ostream& operator<< (std::ostream& stream, const Tableau& tab) {
	
		stream << "[ ";
		for(size_t i=0; i<tab.m_size; ++i){
			stream << tab[i];
			if(i < tab.m_size-1) stream << ", ";
		}
		stream << "]";

		return stream;
	}

};





