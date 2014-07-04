#include "gtest/gtest.h"
#include "parse_iterator.h"
#include "dad_parse_iterator.h" 

//作为测试数据
const char file_data[432]{
	0x8C, 0x19, 0xFC, 0x33, 0x00, 0x37, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0x53, 0x48, 0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x00, 0xA2, 0x17, 0xFE,
		0x9A, 0xC8, 0xC3, 0xA5, 0xC9, 0xCF, 0xD6, 0xA4, 0xD6, 0xB8, 0xCA, 0xFD, 0x00, 0xB8, 0xFE, 0x76,
		0x80, 0x33, 0x9E, 0x53, 0x33, 0x6B, 0x01, 0x45, 0x1F, 0x75, 0x02, 0x45, 0x0A, 0x57, 0x01, 0x45,
		0xAE, 0x5F, 0x02, 0x45, 0x97, 0xFD, 0xB6, 0x4C, 0x99, 0xEC, 0x94, 0x51, 0x49, 0x02, 0x07, 0x01,
		0x00, 0x85, 0x9F, 0x53, 0xAE, 0x07, 0x02, 0x45, 0xAE, 0x07, 0x02, 0x45, 0xB8, 0x0A, 0x01, 0x45,
		0x33, 0x2B, 0x01, 0x45, 0x54, 0x77, 0xA7, 0x4C, 0xD9, 0x1A, 0x84, 0x51, 0xB2, 0x00, 0xD8, 0x02,
		0x80, 0xD6, 0xA0, 0x53, 0x14, 0x06, 0x01, 0x45, 0x8F, 0x2E, 0x01, 0x45, 0x00, 0x3C, 0x00, 0x45,
		0x52, 0x78, 0x00, 0x45, 0x45, 0x68, 0xA6, 0x4C, 0x1D, 0x44, 0x83, 0x51, 0xF3, 0x00, 0x7C, 0x02,
		0xFF, 0xFF, 0xFF, 0xFF, 0x53, 0x48, 0x36, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x3C, 0x00, 0x45,
		0x9A, 0xC8, 0xC3, 0xA5, 0xC6, 0xD6, 0xB7, 0xA2, 0xD2, 0xF8, 0xD0, 0xD0, 0x00, 0x00, 0x7C, 0x02,
		0x80, 0x33, 0x9E, 0x53, 0x14, 0xAE, 0x1B, 0x41, 0x85, 0xEB, 0x1D, 0x41, 0x3D, 0x0A, 0x1B, 0x41,
		0xC3, 0xF5, 0x1C, 0x41, 0x30, 0xA0, 0x90, 0x49, 0xFA, 0x3F, 0x8A, 0x4E, 0xC5, 0x00, 0x00, 0x00,
		0x00, 0x85, 0x9F, 0x53, 0xAE, 0x47, 0x1D, 0x41, 0xAE, 0x47, 0x1D, 0x41, 0x29, 0x5C, 0x1B, 0x41,
		0x14, 0xAE, 0x1B, 0x41, 0x30, 0xF1, 0x5E, 0x49, 0xA0, 0xD4, 0x54, 0x4E, 0xC5, 0x00, 0x00, 0x00,
		0x80, 0xD6, 0xA0, 0x53, 0x14, 0xAE, 0x1B, 0x41, 0xEC, 0x51, 0x1C, 0x41, 0x29, 0x5C, 0x1B, 0x41,
		0x14, 0xAE, 0x1B, 0x41, 0x80, 0x41, 0x22, 0x49, 0x7C, 0x5E, 0x1A, 0x4E, 0xC5, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0x53, 0x5A, 0x30, 0x30, 0x30, 0x30, 0x30, 0x32, 0x00, 0x5C, 0x1B, 0x41,
		0x9A, 0xC8, 0xC3, 0xA5, 0xCD, 0xF2, 0x20, 0x20, 0xBF, 0xC6, 0xA3, 0xC1, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x33, 0x9E, 0x53, 0x5C, 0x8F, 0x06, 0x41, 0x52, 0xB8, 0x06, 0x41, 0x48, 0xE1, 0x02, 0x41,
		0xF6, 0x28, 0x04, 0x41, 0x90, 0xD1, 0x52, 0x49, 0xBB, 0x1E, 0x2A, 0x4E, 0xC5, 0x00, 0xA3, 0x5D,
		0x00, 0x85, 0x9F, 0x53, 0x00, 0x00, 0x04, 0x41, 0x00, 0x00, 0x04, 0x41, 0xD7, 0xA3, 0x00, 0x41,
		0x85, 0xEB, 0x01, 0x41, 0x20, 0x7A, 0x27, 0x49, 0xFC, 0x4D, 0x04, 0x4E, 0xC5, 0x00, 0x59, 0x50,
		0x80, 0xD6, 0xA0, 0x53, 0x85, 0xEB, 0x01, 0x41, 0x52, 0xB8, 0x02, 0x41, 0xB8, 0x1E, 0x01, 0x41,
		0x9A, 0x99, 0x01, 0x41, 0xA0, 0x1F, 0xA9, 0x48, 0xBB, 0x3A, 0x86, 0x4D, 0xC5, 0x00, 0xAF, 0x30,
		0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//定义begin
parse_of_dad begin_value =
{
	(id_of_dad *)(file_data+20),
	(quote_of_dad *)(file_data + 16+32)
};

//定义end
parse_of_dad end_value = {};



//如果要为一组测试(testSuit为blockTest)提供初始化和清理方法，则要定义该testSuit
class DadParseIterator : public testing::Test {
protected:
	//testSuit的初始化函数
	static void SetUpTestCase() {

	}

	//testSuit的清理函数
	static void TearDownTestCase() {
	};
	//SetUpTestCase() 方法在第一个TestCase之前执行
	//TearDownTestCase() 方法在最后一个TestCase之后执行
	//SetUp()方法在每个TestCase之前执行
	//TearDown()方法在每个TestCase之后执行

	//在TestSuit的各测试案例中共享的一些资源，定义为static


};

//默认构造函数，由编译器生成，不用实现代码
TEST_F(DadParseIterator, construct_default)
{
	dad_parse_iterator iter;
}

//主要构造函数，传入两个迭代器和一个T类型的move
TEST_F(DadParseIterator, construct_regular)
{
	dad_parse_iterator iter((char *)file_data,(char *)(file_data+432),begin_value);
}

TEST_F(DadParseIterator, begin)
{
	dad_parse_iterator p((char *)file_data, (char *)(file_data + 432), begin_value);

	//注意，这种方式比较字符串不行，后面的被识别为指针地址。
	//EXPECT_EQ("SH000001", p->idOfDad->id);
	EXPECT_STREQ("SH000001", p->idOfDad->id);
	EXPECT_STREQ("上证指数", p->idOfDad->title);

	EXPECT_EQ((long)1402876800, (long)p->quoteOfDad->quoteTime);

	//使用精度比较浮点数
	EXPECT_TRUE(fabs(2070.70f - (*p).quoteOfDad->open) < std::numeric_limits<float>::epsilon());
	EXPECT_FLOAT_EQ(2070.700F, p->quoteOfDad->open);
	EXPECT_FLOAT_EQ(2087.320F, p->quoteOfDad->high);
	EXPECT_FLOAT_EQ(2069.440F, p->quoteOfDad->low);
	EXPECT_FLOAT_EQ(2085.980F, p->quoteOfDad->close);
	EXPECT_FLOAT_EQ(95939768.00F, p->quoteOfDad->volume);
	EXPECT_FLOAT_EQ(79953076224.00F, p->quoteOfDad->amount);
};

TEST_F(DadParseIterator, end_test)
{
	dad_parse_iterator iter;
	EXPECT_EQ(0, iter->idOfDad);
	EXPECT_EQ(0, iter->quoteOfDad);
};

//++操作
TEST_F(DadParseIterator, operator_increase_test)
{
	dad_parse_iterator p((char *)file_data, (char *)(file_data + 432), begin_value);
	p++;
	EXPECT_STREQ("SH000001", p->idOfDad->id);
	EXPECT_STREQ("上证指数", p->idOfDad->title);
	EXPECT_EQ((long)1402963200, (long)p->quoteOfDad->quoteTime);
};

//++操作改变id
TEST_F(DadParseIterator, operator_increase_id_changed_test)
{
	dad_parse_iterator p((char *)file_data, (char *)(file_data + 432), begin_value);
	++p;
	++p; 
	++p;//每只股票三条记录
	EXPECT_STREQ("SH600000", p->idOfDad->id);
	EXPECT_STREQ("浦发银行", p->idOfDad->title);
	EXPECT_EQ((long)1402876800, (long)p->quoteOfDad->quoteTime);

	p++;
	p++;
	p++;
	EXPECT_STREQ("SZ000002", p->idOfDad->id);
	EXPECT_STREQ("万  科Ａ", p->idOfDad->title);
	EXPECT_EQ((long)1402876800, (long)p->quoteOfDad->quoteTime);

	p++;
	p++;
	p++;

	dad_parse_iterator  iter;
	EXPECT_TRUE((iter==p));

	//到end后，再++，则什么都不做。
	++p;
	EXPECT_EQ(true,iter==p);
};