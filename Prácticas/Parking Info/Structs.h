// types

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct
{
	uint8 u8MaxSlots;
	uint8 u8AvailableSlots;
	uint8 u8NotAvailableSlots;
	uint32 u32MoneyEarn;
}tstParkingInfo;

typedef enum
{
	enSector0 = 0,
	enSector1,
	enSector2,
	enSector3,
	enSector4,
	enMaxSectors
}tenParkingSectors;

// defines

#define SECTOR0_SLOTS									5
#define SECTOR1_SLOTS									10
#define SECTOR2_SLOTS									25
#define SECTOR3_SLOTS									7
#define SECTOR4_SLOTS									12

#define EMPTY_SLOTS										0

#define PARKING_LOT_AVAILABLE 							1
#define PARKING_LOT_UNAVAILABLE 						0

#define PARKING_COST									10

#define INIT_PARKING_SLOTS								\
{														\
	{SECTOR0_SLOTS,SECTOR0_SLOTS,0,0},					\
	{SECTOR1_SLOTS,SECTOR1_SLOTS,0,0},					\
	{SECTOR2_SLOTS,SECTOR2_SLOTS,0,0},					\
	{SECTOR3_SLOTS,SECTOR3_SLOTS,0,0},					\
	{SECTOR4_SLOTS,SECTOR4_SLOTS,0,0}					\
}

// prototypes

void ShowAvailableSlots ( tenParkingSectors enCurrentSector );

void ShowNotAvailableSlots ( tenParkingSectors enCurrentSector );

void ShowEarnedMoney ( tenParkingSectors enCurrentSector );

uint8 u8AddCarToSector( tenParkingSectors enCurrentSector );

uint8 u8RemoveCarFromSector( tenParkingSectors enCurrentSector );

void u8ImportPaymentOfSlot( tenParkingSectors enCurrentSector );
