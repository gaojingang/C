#include <iostream>
#include <fstream>
#include <string>
#include <sstream>     // std::stringstream
#include <cstring>

#include <openssl/md5.h>


using namespace std;


// #include <boost/filesystem/path.hpp>

#define MD5_SECRET_LEN_16     (16)
#define MD5_BYTE_STRING_LEN   (4)


// # 用于替换的头部信息
// # FF FF FF 88 C8 D8 E8 88
const static char* __HIDE_DATAS__ = "FFFFFF88C8D8E888";
// 需要读取/写入多少字节 当前按照8个字节来读取 ，char* 64位系统为8位
const static int BYTE_LENGTH = 8;

// 文件结构体
struct FileNameOpt
{
  string dirName;
  string fileName;
  string name;
  string suffix_str;
};




// 字节数组转为 16进制
string byte2Hex(const char* bytes, int size , bool upper_case)
{
  char const hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B','C','D','E','F'};

  string str;
  for (int i = 0; i < size; ++i) {
    const char ch = bytes[i];
    cout  << ch ;
    str.append(&hex[(ch & 0xF0) >> 4], 1);
    str.append(&hex[ch & 0xF], 1);
  }
  cout <<endl;
  cout << "hex:" << str <<endl;
  return str;
}


int hexCharToInt(char c)
{ 
        if (c >= '0' && c <= '9') return (c - '0');
        if (c >= 'A' && c <= 'F') return (c - 'A' + 10);
        if (c >= 'a' && c <= 'f') return (c - 'a' + 10);
return 0;
}

char* hexstringToBytes(string s)
{         
        int sz = s.length();
        char *ret = new char[sz/2];
        cout << "a:\t" << "avalue:\t" << "b:\t" << "bvalue:\t"  << "a|b:\t" << "char:" <<endl;
        for (int i=0 ; i <sz ; i+=2) {
            int a = hexCharToInt(s.at(i)) << 4;
            int b = hexCharToInt(s.at(i+ 1));
            cout << s.at(i) << "\t" << a << "\t" 
                << s.at(i +1) << "\t" << b << "\t" 
                << (a|b)  << "\t" <<(char)(a|b) << "\t"  << endl;

            // ret[i/2] = (char) ((hexCharToInt(s.at(i)) << 4)
                                // | hexCharToInt(s.at(i+1)));
            // cout <<"a:" <<  a << "\tb:" <<b << "\ta|b:" << (a|b)  << "\tchar:" <<  (char)(a|b)<<endl;
            ret[i/2] = (char) a|b;
            
        }
return ret;
}


string bytestohexstring(char* bytes,int bytelength)
{
  string str("");
  string str2("0123456789abcdef"); 
   for (int i=0;i<bytelength;i++) {
     int b;
     b = 0x0f&(bytes[i]>>4);
char s1 = str2.at(b);
str.append(1,str2.at(b));    
     b = 0x0f & bytes[i];
     str.append(1,str2.at(b));
char s2 = str2.at(b);
   }
   return str;
}

// 将字符串形式的 16进制拆分为 长度相等的 char数组
unsigned char * hexStrtoCharArrays(string hexStr){
  cout << hexStr <<endl;
  cout << hexStr.length() << endl;
  // 判断数组长度，如果
  int arrayLength = hexStr.length() % 2 == 0 ? hexStr.length() / 2 : hexStr.length() / 2 +1;
  
  unsigned char hexChars[8] = {0};

  // for (size_t i = 0; i < arrayLength; i++)
  // {
  //   int index = i * 2;
  //   hexChars[i] = str2Num16(hexStr.c_str() , index);

  // }
  // cout << "hexChars :" << hexChars <<endl;
  return NULL;
}





/**
 * #purpose	: 字符串转十六进制字符串
 * #note	: 可用于汉字字符串
 * #param str		: 要转换成十六进制的字符串
 * #param separator	: 十六进制字符串间的分隔符
 * #return	: 接收转换后的字符串
 */
std::string strToHex(std::string str, std::string separator = "")
{
	const std::string hex = "0123456789ABCDEF";
	std::stringstream ss;
 
	for (std::string::size_type i = 0; i < str.size(); ++i)
		ss << hex[(unsigned char)str[i] >> 4] << hex[(unsigned char)str[i] & 0xf] << separator;
	
	return ss.str();
}



FileNameOpt getFileNameOpt(string filePath){

    FileNameOpt opt;
    // 首先获取最后一个 \ 出现的下标
    string::size_type iPos = filePath.find_last_of('\\') + 1;
    // cout <<"iPos:" << iPos <<endl;  E:\development\IDM\Media\Dir\favorite\da\ 

    // 1. 获取文件夹的目录
    string dirname = filePath.substr(0,iPos);
    // cout << dirname  <<endl;

    //2.获取不带路径的文件名
    string filename = filePath.substr(iPos, filePath.length() - iPos);
    // cout << filename << endl;
  
    //3.获取不带后缀的文件名
    string name = filename.substr(0, filename.rfind("."));
    // cout << name << endl;
  
    //4.获取后缀名
    string suffix_str = filename.substr(filename.find_last_of('.') + 1);
    // cout << suffix_str << endl;

    
    opt.dirName = dirname;
    opt.fileName = filename;
    opt.name = name;
    opt.suffix_str = suffix_str;

    return opt;


}
// 计算字符串的MD5值
string MD5(const string& src )
{

    MD5_CTX ctx;
 
    string md5String;
    unsigned char md[MD5_SECRET_LEN_16] = { 0 };
    char tmp[MD5_BYTE_STRING_LEN] = { 0 };
 
    MD5_Init( &ctx );
    MD5_Update( &ctx, src.c_str(), src.size() );
    MD5_Final( md, &ctx );
 
    for( int i = 0; i < 16; ++i )
    {
        memset( tmp, 0x00, sizeof( tmp ) );
        snprintf( tmp,sizeof(tmp) , "%02X", md[i] );
        md5String += tmp;
    }

  return md5String;
}


// 读取文件头信息
string readFileHead(const char *filePath ){

    cout << "file:" << filePath << endl;
    ifstream fin(filePath,ios::in | ios::binary);
    if (!fin.is_open()){
     cout <<"文件打开失败!" << endl;
      return NULL;
    }   
     // 4 读取文件

    int length = 8;
    char *bytes = new char[8];
    fin.seekg(0,ios::beg);;
    fin.read(bytes,length);

    string hexStr = byte2Hex(bytes,length,true);

    // 5 关闭文件
    fin.close();
    return hexStr;

}




// 写入文件头信息
void writeFileHead(const char *filePath){

    cout <<"修改二进制文件!" << filePath <<endl;
    // 1 导入头文件
    // 2 创建文件流
    ofstream fout(filePath,ios::out | ios::binary);

    // 3 打开文件
    // ifs.open("test1.txt",ios::in | ios::binary);
    if (!fout.is_open()){
        cout <<"文件打开失败!" << endl;
        return ;
    }
    // 4 写入文件

    int length = 8;
    fout.seekp(0,ios::beg);
    fout.write(__HIDE_DATAS__,length);

    // 5 关闭文件
    fout.close();
    cout <<"文件写入成功!" <<endl;

}

    // string 与 char * 的转化
    //  string  == >char *   
    // string str = "";
    // str.c_str();

    // char *  --> string 
    // char * arrs = "hello";
    // string str = string(arrs);

/**
 * 
 * 对传入的文件进行头文件信息加密 
 * 
 * @Parma filepath 文件路径
 * 
 * **/
void encryptFile(string filePath){

    string kvfFilePath ;
    cout << "filepath:" << filePath << endl;
    // 编辑二进制文件需要传入 in|out|binary 三种mode 并且需要使用fstream对象
    fstream ioFile(filePath.c_str(),ios::in | ios::out | ios::binary);
    if (!ioFile.is_open()){
     cout <<"文件打开失败!" << endl;
      return;
    }   
     // 4 读取文件

     // 创建临时的字节数组
    char *bytes = new char[BYTE_LENGTH];
    // 移动到首位取编辑
    ioFile.seekg(0,ios::beg);;
    // 从0位置开始读取 8字节 数据
    ioFile.read(bytes,BYTE_LENGTH);
    // 将读取的到数据转为 16进制数组
    string hexStr = byte2Hex(bytes,BYTE_LENGTH,true);


    // 写入文件
    // 从0位置开始写入数据，此数据会替换当前位置的
    ioFile.seekg(0,ios::beg);;
    // 写入的数据是定义好的要替换的文件头信息，长度为 数组长度
    char* hideBytes = hexstringToBytes(__HIDE_DATAS__);
    ioFile.write(hideBytes,BYTE_LENGTH);
    
    
         // 4 读取文件

     // 创建临时的字节数组
    char *bytes2 = new char[BYTE_LENGTH];
    // 移动到首位取编辑
    ioFile.seekg(0,ios::beg);;
    // 从0位置开始读取 8字节 数据
    ioFile.read(bytes,BYTE_LENGTH);
    // 将读取的到数据转为 16进制数组
    string hexStr2 = byte2Hex(bytes2,BYTE_LENGTH,true);
    
    cout << "__HIDE_DATAS__ hexStr2:" << hexStr2 << ", size:" <<sizeof(hexStr2) <<endl;

    
    
    // 5 关闭文件
    ioFile.close();




    // os.rename(file,newName)
    // #返回 md5(文件名)、原始文件的头文件 hex  记录到文件中  ，最终将文件加密

    FileNameOpt  opt =  getFileNameOpt(filePath);
    cout << "dirname:" <<opt.dirName <<endl;
    cout << "filename:" <<opt.fileName <<endl;
    cout << "name:" <<opt.name <<endl;
    cout << "suffix_str:" <<opt.suffix_str <<endl;
    // 修改文件名
    // 原始文件名经过 md5加密生成
    // 获取文件名 ，用来做md5
    // md5Name = md5(name)
    // # 重命名文件后缀，增加特殊后缀，下次判断如果是该后缀文件，就不再处理
    // newName = dir + os.path.sep + md5Name  + "@" + f_headHex + ".kvf"
    string md5strName = MD5(opt.name);
    cout << "md5strName:" <<md5strName <<endl;
    cout <<  "hexStr:" << hexStr << endl;
    string modifyFileName = md5strName + "@"  + hexStr + ".kvf";
    cout <<  "modifyFileName:" << modifyFileName << endl;
    // dirname 默认带最后一个\ 

    kvfFilePath =  opt.dirName + modifyFileName;
    cout << "filepath:" <<filePath.c_str() <<endl;
    cout << "kvfFilePath:" <<kvfFilePath.c_str() <<endl;

    if (!rename(filePath.c_str(),kvfFilePath.c_str())){
      cout << "重命名成功!" << endl;
    } else {
      cout << "重命名失败!" << endl;
    }


    // return hexStr;

}






/**
 * 
 * 对传入的文件进行头文件信息解密
 * 
 * @Parma filepath 文件路径
 * 
 * **/
void decryptFile(string filePath){

    // 首先解析文件名，获取到文件基本信息，读取文件名@之后的数字，用来写入头文件信息
    cout << filePath <<endl;
    FileNameOpt  opt =  getFileNameOpt(filePath);
    cout << "dirname:" <<opt.dirName <<endl;
    cout << "filename:" <<opt.fileName <<endl;
    cout << "name:" <<opt.name <<endl;
    cout << "suffix_str:" <<opt.suffix_str <<endl;

    // 判断结尾是否为 kvf ，如果不是不做处理
    if (opt.suffix_str != "kvf"){
      cout <<"不是kvf加密文件，不做处理!" << endl;
      return ;
    }
    // 解析其中的hexString 
    string::size_type iPosAt = opt.name.find_last_of('@') + 1;
    string modifyHexStr = opt.name.substr(iPosAt,opt.name.length() -1);
    char* modifyBytes = hexstringToBytes(modifyHexStr);
    
    // 编辑二进制文件需要传入 in|out|binary 三种mode 并且需要使用fstream对象
    fstream ioFile(filePath.c_str(),ios::in | ios::out | ios::binary);
    if (!ioFile.is_open()){
     cout <<"文件打开失败!" << endl;
      return;
    }   

     // 4 读取文件
    //  // 创建临时的字节数组
    // char *bytes = new char[BYTE_LENGTH];
    // // 移动到首位取编辑
    // ioFile.seekg(0,ios::beg);;
    // // 从0位置开始读取 8字节 数据
    // ioFile.read(bytes,BYTE_LENGTH);
    // // 将读取的到数据转为 16进制数组
    // string hexStr = byte2Hex(bytes,BYTE_LENGTH,true);

    // 写入文件
    // 从0位置开始写入数据，此数据会替换当前位置的
    ioFile.seekp(0,ios::beg);;
    // 写入的数据是定义好的要替换的文件头信息，长度为 数组长度  
    ioFile.write(modifyBytes,BYTE_LENGTH);

    cout <<"写入成功!" << endl;


     // 读取文件
    //  // 创建临时的字节数组
    char *bytes = new char[BYTE_LENGTH];
    // 移动到首位取编辑
    ioFile.seekg(0,ios::beg);;
    // 从0位置开始读取 8字节 数据
    ioFile.read(bytes,BYTE_LENGTH);
    // 将读取的到数据转为 16进制数组
    string rhexStr = byte2Hex(bytes,BYTE_LENGTH,true);
    cout << "readhexStr:" <<rhexStr <<endl;



    // 5 关闭文件
    ioFile.close();
    // return hexStr;
    cout <<"解密成功!" <<endl;
    // 重命文件
    
  
}



int main(int argc, char const *argv[])
{

    // 传入文件路径
    // 执行加密操作
    // 1 读取头文件类型，当前按照


    // string filePath = "E:\\development\\IDM\\Media\\Dir\\favorite\\da\\8d6ad0bf6a5ffe00e7cecba5b10ad2c8@0000002066747970.kvf";
    // string filePath = "E:\\development\\IDM\\Media\\Dir\\favorite\\da\\DBC352AB68099537C7025ADC8016D6DF@4646464646463838.kvf";
    // string filePath = "E:\\development\\IDM\\Media\\Dir\\test\\f0072fac1736ccd49c38379369c76ed6@0000001466747970.kvf";
    string filePath =     "E:\\development\\IDM\\Media\\Dir\\test\\ECE926D8C0356205276A45266D361161@0000001466747970.kvf";
    // string filePath = "E:\\development\\IDM\\Media\\Dir\\test\\ffff.mp4";

    // string ext_m4a = "0000001466747970";
    string ext_m4a = __HIDE_DATAS__;
    // hexstringToBytes(ext_m4a);

   char* sdf = hexstringToBytes(ext_m4a);
    
    for(int j = 0;j<ext_m4a.length() /2 ;j++)
   {
      // printf("\n%x",sdf[j]);
      cout << sdf[j] <<endl;
   }


    // cout << "读写字节数:" << BYTE_LENGTH <<endl;
    
    // cout << "替换的内容:" << __HIDE_DATAS__ <<endl;

    // FileNameOpt  opt =  getFileNameOpt(filePath);

    // cout << "filename:" <<opt.fileName <<endl;
    // cout << "name:" <<opt.name <<endl;
    // cout << "suffix_str:" <<opt.suffix_str <<endl;

    
    // cout << MD5("fupeng") << endl;
    // cout << MD5("123") << endl;
    // cout << MD5(opt.fileName) << endl;

    // string hexstr = readFileHead(filepath.c_str());
    // cout << "hexstr:" << hexstr <<endl;
    // if (ext_m4a == hexstr){
    //      cout << "hexstr == ext_m4a" <<endl;
    //     // 修改头文件信息
    //     writeFileHead(filepath.c_str());

    // }else{
    //     cout << "hexstr !!!= ext_m4a" <<endl;
    // }

    // encryptFile(filePath);
    // decryptFile(filePath);


    return 0;
}
