#include <iostream>
#include <vector>

/*class Arrow{
	private:
		std::string likeness;
		int value;
	public:
		Arrow(){
			likeness="";
		}
		Arrow& operator--(int){
			likeness+="--";
			return *this;
		}
		Arrow& operator>(int a){
			likeness+=">";
			value=a;
			return *this;
		}
		void print(){
			std::cout <<"Value: " << value << " This vector looks like this: "<< likeness << std::endl;
		}
};

class MakeShape{
	public:
		MakeShape operator()(){
			
			return *this;
		}
};*/
class BrainFuckInterpreter{
	private:
		std::vector<int> memory_cells;
		unsigned int pointer;
		int repeat;
	public:
		BrainFuckInterpreter(){
			memory_cells = std::vector<int>(256, 0);
			pointer=0;
			repeat=1;
		}
		BrainFuckInterpreter(int memory_size){
			memory_cells = std::vector<int>(memory_size, 0);
			pointer=0;
			repeat=1;
		}
		BrainFuckInterpreter& operator-(){
			for(int i=0;i<repeat;i++){
				if(memory_cells[pointer]>0){
					memory_cells[pointer]--;	
				}
			
			}
			repeat=1;
			return *this;
		}
		BrainFuckInterpreter& operator+(){
			for(int i=0;i<repeat;i++){
				if(memory_cells[pointer]<65535){
					memory_cells[pointer]++;	
				}
			}
			repeat=1;
			return *this;
		}
		BrainFuckInterpreter& operator>(int a){
			for(int i=0;i<repeat;i++){
				if(pointer<memory_cells.size()-1){
					
					pointer++;
				}
			}
			repeat=1;
			
			return *this;
		}
		BrainFuckInterpreter& operator<(int a){
			for(int i=0;i<repeat;i++){
				if(pointer>0){
					
					pointer--;
				}
			}
			repeat=1;
			return *this;
		}
		BrainFuckInterpreter& operator~(){
			for(int i=0;i<repeat;i++){
				print();
			}
			repeat=1;
			return *this;
		}
		BrainFuckInterpreter& operator!(){
			for(int i=0;i<repeat;i++){
				read();
			}
			repeat=1;
			return *this;
		}
		BrainFuckInterpreter& operator*(int mul){
			repeat*=mul;
			return *this;
		}
		void print(){
			unsigned char c=memory_cells[pointer];
			std::cout <<c;
		}
		void read(){
			int r=0;
			std::cin>>r;
			memory_cells[pointer]=r;
		}
};

int main(){
	BrainFuckInterpreter _(256);
	_*0x68; +_; ~_; _>0;
	_*0x65; +_; ~_; _>0;
	_*0x6C; +_; ~_; ~_; _>0;
	_*0x6F; +_; ~_; _>0;
	_*0x20; +_; ~_; _>0;
	_*0x77; +_; ~_; _>0;
	_*0x6F; +_; ~_; _>0;
	_*0x72; +_; ~_; _>0;
	_*0x6C; +_; ~_; _>0;
	_*0x64; +_; ~_; _>0;
	_*0x21; +_; ~_; _>0;
	return 0;
}