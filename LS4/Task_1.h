#pragma once
#include "Common.h"

namespace My {
	class Vector
	{
	public:
		Vector() = default;

		void push_back(int value);
		void pop_back();
		void pop_front();
		void print();
		void sort();


		size_t size() { return m_size; }
		size_t capacity() { return m_capacity; }
		bool empty() { return m_size == 0; }

		~Vector()
		{
			delete[] m_date;
		}
	private:
		size_t m_size = 0;
		size_t m_capacity = 0;
		int* m_date = nullptr;
	};

	void Vector::push_back(int value)
	{
		if (m_date)
		{
			if (m_size + 1 > m_capacity)
			{
				m_capacity *= 2;
				int* temp_date = new int[m_capacity];
				std::copy(m_date, m_date + m_size, temp_date);
				delete[] m_date;
				m_date = temp_date;
			}
		}
		else
		{
			m_date = new int[BUFFER_SIZE];
			m_capacity = BUFFER_SIZE;
		}
		m_date[m_size++] = value;
	}

	void Vector::pop_back()
	{
		if (!empty())
		{
			--m_size;
		}
	}

	void Vector::pop_front()
	{
		if (!empty())
		{
			--m_size;
			for (size_t i = 0; i < m_size; ++i)
			{
				m_date[i] = m_date[i + 1];
			}
		}
	}

	void Vector::sort()
	{
		if (m_size > 1)
		{
			int i, temp, j;
			for (i = 1; i < m_size; ++i)
			{
				temp = m_date[i];
				j = i - 1;

				while (j >= 0 && m_date[j] > temp)
				{
					m_date[j + 1] = m_date[j];
					j = j - 1;
				}
				m_date[j + 1] = temp;
			}
		}
	}

	void Vector::print()
	{
		if (!empty())
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				std::cout << m_date[i] << " ";
			}
		}
		else
		{
			std::cout << "Stack is empty\n";
		}
	}
}