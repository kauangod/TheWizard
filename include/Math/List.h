#pragma once
#include <iostream>
#include "../Entities/Entity.h"
namespace Math
{
	/* Iterator Tutorial used: https://www.youtube.com/watch?v=F9eDv-YIOQ0 */
	template<typename Element>
	
	class ListIterator
	{
	public:
		using PointerType = Element*; 
		using ValuePointer = typename Element::ValueType*;
		using ValueReference = typename Element::ValueType&;
	private:
		Element* m_ptr;
			
	public:
		ListIterator(PointerType ptr = NULL):
		m_ptr(ptr)
		{
		}

		~ListIterator()
		{
			m_ptr = NULL;
		}

		ListIterator& operator++()
		{
			m_ptr = m_ptr->next;
			return *this;
		}
		
		ListIterator operator++(int)
		{
			ListIterator it = *this;
			++(*this);
			return it;
		}
		
		bool operator!=(ListIterator it)
		{
			return !((*this).m_ptr == it.m_ptr);
		}
			
		//typename Element::ValueType& 
		
		ValuePointer operator*()
		{
			return m_ptr->data;
		}

		//typename Element::ValueType* 
				
		ValuePointer operator->()
		{
			return m_ptr->data;
		}

		void operator=(ListIterator it)
		{
			this->m_ptr = it.m_ptr;
		}

	};

	template< typename T>
	class List
	{
	public:
		
		template <typename TE> 
		class Element
		{
		public:
			using ValueType = TE;
		public:
			Element<TE>* next;
			TE* data;
			Element( T* dt = NULL):
				data(dt),next(NULL)
			{
			}

			~Element()
			{
				data = NULL;
				next = NULL;
			}
		};

		Element<T>* pFirst;
		Element<T>* pLast;
	
	private:
		int size;

	public:
		using Iterator = ListIterator<Element<T>>;
		using ValueType = T;
	public:
		List():
			pFirst(NULL),
			pLast(NULL),
			size(0)
		{
		}

		~List()
		{
			this->clear();
			pFirst = NULL;
			pLast = NULL;
		}

		void insert_front(T* dt)
		{
			if (!dt)
			{
				std::cout << "ERROR: List NULL Insertion" << std::endl;
				return;
			}
			Element<T>* pAux = new Element<T>(dt);
			if (!pAux)
			{
				std::cout << "ERROR: Failed to Allocate Memory" << std::endl;
				return;
			}
			size++;
			if (!pFirst)
			{
				pFirst = pAux;
				pLast = pAux;
				pAux = NULL;
				return;
			}
			pAux->next = pFirst;
			pFirst = pAux;
			pAux = NULL;
		}

		void insert_back(T* dt)
		{
			if (!dt)
			{
				std::cout << "ERROR: List NULL Insertion" << std::endl;
				return;
			}
			Element<T>* pAux = new Element<T>(dt);
			if (!pAux)
			{
				std::cout << "ERROR: Failed to Allocate Memory" << std::endl;
				return;
			}
			size++;
			if (!pFirst)
			{
				pFirst = pAux;
				pLast = pAux;
				pAux = NULL;
				return;
			}
			pLast->next = pAux;
			pLast = pAux;
			pAux = NULL;
		}

		T* operator[](int idx)
		{
			if (idx < 0 || idx > size)
			{
				std::cout << "ERROR: List Segmentation Fault" << std::endl;
				exit(1);
			}
			Element<T> *pAux = pFirst;
			if(!pAux)
			{
				std::cout << "ERROR: NULL Pointer List Index";
				exit(1);
			}
			for (int i = 0; i < idx; i++)
			{
				pAux = pAux->next;
			}
			return pAux->data;
		}

		const bool empty() const { return (size == 0 ? true : false); }

		const int getSize() const { return size; }

		void remove(int idx)
		{
			if (idx < 0 || idx > size)
			{
				std::cout << "ERROR: List Segmentation Fault" << std::endl;
				return;
			}
			if (empty())
				return;
			Element<T>* pAux = pFirst;
			Element<T>* pAuxprev = NULL;
			for (int i = 0; i < idx; i++)
			{
				pAuxprev = pAux;
				pAux = pAux->next;
			}
			if (!pAux)
			{
				std::cout << "ERROR: Can't Remove a NULL Element" << std::endl;
				return;
			}
			if (!pAuxprev)
			{
				if (pAux == pLast)
				{
					pLast = NULL;
					pFirst = NULL;
				}
				else
					pFirst = pAux->next;
				delete pAux;
				pAux = NULL;
				size--;
				return;
			}
			if (pAux == pLast)
				pLast = pAuxprev;
			pAuxprev->next = pAux->next;
			delete pAux;
			pAux = NULL;
			pAuxprev = NULL;
			size--;
		}

		void clear()
		{
			if (empty())
				return;
			Element<T>* pAux = NULL;
			int size_aux = size;
			for (int i = 0; i < size_aux; i++)
			{
				remove(0);
			}
		}

		Iterator begin()
		{
			return Iterator(pFirst);
		}	
		
		Iterator end()
		{
			return Iterator(pLast->next);
		}
	};
	typedef List<Entities::Entity> EntityTList;
}
