namespace Math
{
    template<typename T>
    class Coord
    {
    public:
        T x;
        T y;
    public:
        Coord(T x = 0, T y = 0):
            x(x),
            y(y)
        {
        }
        
        ~Coord()
        {
        }
        // SobreCarga de operador = para o lado esquerdo receber o valor
	// ao lado direito.
        void operator=(Coord<T> right)
        {
            x = right.x;
            y = right.y;
        }
	// SobreCarga de operador - para retornar um coord com as respectivas
	// coordernadas subtraidos
	Coord<T> operator-(Coord<T> right)
	{
	    return Coord<T>(x - right.x, y - right.y);
	}
	// SobreCarga -= para subtrair os respectivos valores "inplace"
	void operator-=(Coord<T> right)
        {
            this->x -= right.x;
 	    this->y -= right.y;	    
	}
	// SobreCarga de operador * para retornar um coord
	// com mutiplacacao das respectivas coordenadas por escalar
	// (int, float, double, etc...)
	template<typename TU>
        Coord<T> operator*(TU right)
        {
            return Coord<T>(right * x, right * y);
        }
	// SobreCarga *= para mutiplicar por escalar "inplace"
	template<typename TU>
        void operator*=(TU right)
        {
	    this->x *= right;
	    this->y *= right;
        }
	// SobreCarga de operador + para retornar
	// um coord com as coordenadas somadas
	Coord<T> operator+(Coord<T> right)
        {
            return Coord<T>(this->x + right.x, this->y + right.y);
        }
	// SobreCarga += para somar as coordenadas "inplace"
	void operator+=(Coord<T> right)
        {
            this->x += right.x;
	        this->y += right.y;
        }
	// SobreCarga de operador / para retornar um coord com
	//  a divisao das coordenadas por um escalar
	template<typename TU>
	Coord<T> operator/(TU right)
	{
	    return Coord<T>(this->x / right, this->y / right);
	}
	// SobreCarga /= para dividir um coord por um escalar "inplace"
	template<typename TU>
	void operator/=(TU right)
	{
   	    this->x /= right;
	    this->y /= right;
	}
    };    
    typedef Coord<float>    	Coordf;
    typedef Coord<unsigned int> Coordu;
    typedef Coord<int>		    Coordi;
}
