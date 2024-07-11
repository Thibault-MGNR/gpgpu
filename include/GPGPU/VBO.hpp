#pragma once

class VBO{
	public:
		VBO();
		~VBO();

		void init();
		void bind();
	
	private:
		unsigned int _index = 0;
};