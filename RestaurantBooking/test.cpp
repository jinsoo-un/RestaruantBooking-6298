#include "gmock/gmock.h"
#include "booking_scheduler.cpp"

TEST(BookingSchedulerTest, 예약은정시에만가능하다정시가아닌경우예약불가) {
	//arrange
	tm notOnTheHour = { 0 };
	notOnTheHour.tm_year = 2021 - 1900;		// tm 구조체는 1900 년도부터 데이터 기록
	notOnTheHour.tm_mon = 03 - 1;			// tm 구조체는 month 를 0 부터 관리
	notOnTheHour.tm_mday = 26;
	notOnTheHour.tm_hour = 9;				// 9 시
	notOnTheHour.tm_min = 5;				// 5 분 , 정각이 아님
	notOnTheHour.tm_isdst = -1;				// 1 : daylight 를 자동 설정으로 맡김
	mktime(&notOnTheHour);					// 나머지 tm 구조체 맴버 값에 대해 자동으로 계산하여 채움
	Customer customer{ "Fake name", "010-1234-5678" };
	Schedule* schedule = new Schedule{ notOnTheHour, 1, customer };
	BookingScheduler bookingScheduler{ 3 };

	//act
	EXPECT_THROW({
		bookingScheduler.addSchedule(schedule);
		}, std::runtime_error);

	//assert
	//expected runtime exception
}

TEST(BookingSchedulerTest, 예약은정시에만가능하다정시인경우예약가능) {

}

TEST(BookingSchedulerTest, 시간대별인원제한이있다같은시간대에Capacity초과할경우예외발생) {

}

TEST(BookingSchedulerTest, 시간대별인원제한이있다같은시간대가다르면Capacity차있어도스케쥴추가성공) {

}

TEST(BookingSchedulerTest, 예약완료시SMS는무조건발송) {

}

TEST(BookingSchedulerTest, 이메일이없는경우에는이메일미발송) {

}

TEST(BookingSchedulerTest, 이메일이있는경우에는이메일발송) {

}

TEST(BookingSchedulerTest, 현재날짜가일요일인경우예약불가예외처리) {

}

TEST(BookingSchedulerTest, 현재날짜가일요일이아닌경우예약가능) {

}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}