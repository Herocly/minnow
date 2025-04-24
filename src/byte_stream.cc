#include "byte_stream.hh"
#include <deque>

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) :buffer(), capacity_( capacity ){}
//ByteStream类的构造函数，初始化容量为capacity

void Writer::push( string data )
{
  if(is_closed()){
    return;
  }
  uint64_t left_capacity = available_capacity();
  std::string to_write = data.substr(0,left_capacity);
  for(size_t i = 0;i < to_write.size();i++){
    buffer.push_back(data[i]);
    number_pushed ++;
  }
  // cout << buffer;
}

void Writer::close()
{
  if(is_closed()){
    input_end = true;
    return;
  }
  input_end = true;
  // Your code here.
}

bool Writer::is_closed() const
{
  return input_end;
}

uint64_t Writer::available_capacity() const
{
  return {capacity_ - buffer.size()}; // Your code here.
}

uint64_t Writer::bytes_pushed() const
{
  return number_pushed; // Your code here.
}

string_view Reader::peek() const
{
  if (buffer.empty()){
    return "";
  }
  return {&buffer.front(),1}; // Your code here.
}

void Reader::pop( uint64_t len )
{
  if(is_finished()) return;
  for(size_t i = 0;i < len && !buffer.empty();i++){
    buffer.pop_front();
    number_popped ++;
  }
  // 循环对buffer进行pop的front操作，直到达到len或者buffer为空
}

bool Reader::is_finished() const
{ 
  return input_end  && buffer.empty(); // Your code here.
}

uint64_t Reader::bytes_buffered() const
{
  return buffer.size(); // Your code here.
}

uint64_t Reader::bytes_popped() const
{
  return number_popped; // Your code here.
}

