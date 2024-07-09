#pragma once

class VBO{
	public:
		VBO();
		~VBO();
		void bind();
	
	private:
		unsigned int index = 0;
};