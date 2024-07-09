#pragma once 

class VAO{
	public:
		VAO();
		~VAO();
		void bind();
	
	private:
		unsigned int index = 0;
};