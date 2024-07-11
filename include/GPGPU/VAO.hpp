#pragma once 

class VAO{
	public:
		VAO();
		~VAO();

		void init();
		void bind();
	
	private:
		unsigned int _index = 0;
};