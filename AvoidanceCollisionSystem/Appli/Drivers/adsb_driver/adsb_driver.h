/********************************************************************************
 * @file           : adsb_driver.h
 * @brief          : Header file for the ADSB module
 ******************************************************************************
 * @Created        : April 2, 2026
 *
 * @Author 		   : german noriega
 *
 *******************************************************************************/

#ifndef ADSB_DRIVER_ADSB_DRIVER_H_
#define ADSB_DRIVER_ADSB_DRIVER_H_


/******************************************************************************
 *
 * @defgroup ADSB Driver Private Includes
 *
 *****************************************************************************/

#include <stdint.h>

/******************************************************************************
 *
 * @defgroup ADSB Buffer and Frame Definitions
 *
 *****************************************************************************/

#define MODES_CRC24_POLY 						0xFFF409  		// Generador Mode S (24 bits)

#define RX_BUFF_SZ 								128 /*!<  Specifies the size of the Ring Buffer for the UARTRx comming from DMA*/

#define FRAME_SZ								28  /*!<  Specifies the size of ADSB Frames (probably would change)*/

#define NUM_OF_FRAMES							500  /*!<  Specifies the number of ADSB Frames stored in a exclusive Ring Buffer for each Downlink Format(probably would change)*/

#define DF_BUFF_SZ								NUM_OF_FRAMES /*!<  Specifies the total size of ADSB Frames stored in a exclusive Ring Buffer for each Downlink Format(probably would change)*/

#define CPR_BUFF_SZ								25	/*!<  Specifies the number of CPR Frames stored in a exclusive Ring Buffer for each Even and Odd CPR Frames*/

#define ADSB_RGBUFF_FST_HALF_CALLBACK				0	/*!< Identifies the first-half callback event of the ADS-B ring buffer data processing */
#define ADSB_RGBUFF_SND_HALF_CALLBACK				1   /*!< Identifies the second-half callback event of the ADS-B ring buffer data processing */

#define ADSB_DOWNLINK_BYTE_SIZE						2	/*!< Specifies the number of bytes used to represent the ADS-B Downlink Format field */
#define ADSB_CAPABILITY_BYTE_SIZE					1	/*!< Specifies the number of bytes used to represent the ADS-B Capability field */
#define ADSB_ICAOADDRESS_BYTE_SIZE					6	/*!< Specifies the number of bytes used to represent the 24-bit ICAO aircraft address */
#define ADSB_TYPECODE_BYTE_SIZE						2	/*!< Specifies the number of bytes used to represent the ADS-B Type Code field */
#define ADSB_MESSAGE_BYTE_SIZE						13	/*!< Specifies the number of bytes used to represent the ADS-B Message Extension (ME) field */
#define ADSB_PARITY_BYTE_SIZE						6	/*!< Specifies the number of bytes used to represent the ADS-B Parity / CRC field */

#define SHIFT_INDEX 							0	/*!< Index used to access the bit-shift position within a field descriptor array */
#define MASK_INDEX								1	/*!< Index used to access the bit-mask value within a field descriptor array */

#define AIR_ID_CATEGORY_INDEX					1	/*!< Index identifying the Aircraft Category field within the Airborne Identification message */
#define AIR_ID_FIRST_CALLSIGN_INDEX				2	/*!< Index identifying the first encoded callsign character field */
#define AIR_ID_LAST_CALLSIGN_INDEX				10	/*!< Index identifying the last encoded callsign character field */

#define GND_POS_MOV_INDEX						1	/*!< Index identifying the Ground Speed field */
#define GND_POS_S_INDEX							2	/*!< Index identifying the Ground Track Status flag field */
#define GND_POS_TRK_INDEX						3	/*!< Index identifying the Ground Track Angle field */
#define GND_POS_T_INDEX							4	/*!< Index identifying the Time flag field */
#define GND_POS_F_INDEX							5	/*!< Index identifying the CPR Even/Odd format flag field */
#define GND_POS_LAT_INDEX						6	/*!< Index identifying the encoded CPR Latitude field */
#define GND_POS_LON_INDEX						7	/*!< Index identifying the encoded CPR Longitude field */

#define AIR_POS_SS_INDEX						1	/*!< Index identifying the Surveillance Status field */
#define AIR_POS_SAF_INDEX						2	/*!< Index identifying the Single Antenna Flag (SAF) field */
#define AIR_POS_ALT_INDEX						3	/*!< Index identifying the encoded altitude field */
#define AIR_POS_T_INDEX							4	/*!< Index identifying the Time flag field */
#define AIR_POS_F_INDEX							5	/*!< Index identifying the CPR Even/Odd format flag field */
#define AIR_POS_LAT_INDEX						6	/*!< Index identifying the encoded CPR Latitude field */
#define AIR_POS_LON_INDEX						7	/*!< Index identifying the encoded CPR Longitude field */

#define AIR_VEL_ST_INDEX						1	/*!< Index identifying the Velocity Subtype field */
#define AIR_VEL_IC_INDEX						2	/*!< Index identifying the Intent Change (IC) flag field */
#define AIR_VEL_IFR_INDEX						3	/*!< Index identifying the IFR Capability flag field */
#define AIR_VEL_NUC_INDEX						4	/*!< Index identifying the Navigation Uncertainty Category (NUC) field */
#define AIR_VEL_Dew_INDEX						5	/*!< Index identifying the East/West velocity direction flag field */
#define AIR_VEL_Vew_INDEX						6	/*!< Index identifying the East/West velocity magnitude field */
#define AIR_VEL_Dns_INDEX						7	/*!< Index identifying the North/South velocity direction flag field */
#define AIR_VEL_Vns_INDEX						8	/*!< Index identifying the North/South velocity magnitude field */

#define AIR_VEL_SH_INDEX						9	/*!< Index identifying the Heading Status (SH) flag field */
#define AIR_VEL_HDG_INDEX						10	/*!< Index identifying the Heading value field */
#define AIR_VEL_T_INDEX							11	/*!< Index identifying the Velocity Type field (Ground Speed or Airspeed) */
#define AIR_VEL_AS_INDEX						12	/*!< Index identifying the Airspeed or Ground Speed magnitude field */


#define AIR_VEL_VrSrc_INDEX                     13    /*!< Index identifying the Vertical Rate source field */
#define AIR_VEL_Svr_INDEX                       14    /*!< Index identifying the Vertical Rate sign flag field */
#define AIR_VEL_VR_INDEX                        15    /*!< Index identifying the Vertical Rate magnitude field */
#define AIR_VEL_SDif_INDEX                      16    /*!< Index identifying the Differential Altitude sign flag field */
#define AIR_VEL_dAlt_INDEX                      17    /*!< Index identifying the Differential Barometric Altitude field */

#define AIRCRFT_STATUS_ST_INDEX                 1    /*!< Index identifying the Aircraft Status Subtype field */
#define AIRCRFT_STATUS_ES_INDEX                 2    /*!< Index identifying the Emergency / Priority Status field */
#define AIRCRFT_STATUS_ACAS_INDEX               3    /*!< Index identifying the ACAS Resolution Advisory information field */

#define TARGETSS_ST_INDEX						1	 /*!< Index identifying the Target State and Status Subtype field */

#define TARGETSS_AUTOPILOT_FLAG_INDEX           2    /*!< Index identifying the Autopilot Engagement status flag field */
#define TARGETSS_VAVN_FLAG_INDEX                3    /*!< Index identifying the VNAV (Vertical Navigation) mode status flag field */
#define TARGETSS_ALTITUDE_FLAG_INDEX            4    /*!< Index identifying the Altitude Hold / Capture mode status flag field */
#define TARGETSS_APPROACH_FLAG_INDEX            5    /*!< Index identifying the Approach mode status flag field */
#define TARGETSS_SELECTED_ALTITUDE_INDEX        6    /*!< Index identifying the Selected Target Altitude field */
#define TARGETSS_SELECTED_TRACK_INDEX           7    /*!< Index identifying the Selected Target Track Angle field */

#define AIR_OP_STAT_V0_ST_INDEX                 1    /*!< Index identifying the Aircraft Operational Status Subtype (Version 0) field */
#define AIR_OP_STAT_V0_CC4_INDEX                2    /*!< Index identifying Capability Class 4 information field */
#define AIR_OP_STAT_V0_CC3_INDEX                3    /*!< Index identifying Capability Class 3 information field */
#define AIR_OP_STAT_V0_CC2_INDEX                4    /*!< Index identifying Capability Class 2 information field */
#define AIR_OP_STAT_V0_CC1_INDEX                5    /*!< Index identifying Capability Class 1 information field */
#define AIR_OP_STAT_V0_OM4_INDEX                6    /*!< Index identifying Operational Mode 4 information field */
#define AIR_OP_STAT_V0_OM3_INDEX                7    /*!< Index identifying Operational Mode 3 information field */
#define AIR_OP_STAT_V0_OM2_INDEX                8    /*!< Index identifying Operational Mode 2 information field */
#define AIR_OP_STAT_V0_OM1_INDEX                9    /*!< Index identifying Operational Mode 1 information field */

#define PARSING_EVENODD_FRAME_SHIFT             34   	 /*!< Bit shift position used to extract the CPR Even/Odd frame format flag */
#define PARSING_EVENODD_FRAME_MASK              0x01     /*!< Bit mask used to isolate the CPR Even/Odd frame format flag */
#define PARSING_CPR_LAT_SHIFT                   17    	 /*!< Bit shift position used to extract the encoded CPR Latitude field */
#define PARSING_CPR_LAT_MASK                    0x1FFFF  /*!< Bit mask used to isolate the 17-bit encoded CPR Latitude value */
#define PARSING_CPR_LON_SHIFT                   0   	 /*!< Bit shift position used to extract the encoded CPR Longitude field */
#define PARSING_CPR_LON_MASK                    0x1FFFF  /*!< Bit mask used to isolate the 17-bit encoded CPR Longitude value */
#define PARSING_TC_SHIFT                        51    	 /*!< Bit shift position used to extract the ADS-B Type Code field */
#define PARSING_TC_MASK                         0x1F     /*!< Bit mask used to isolate the 5-bit ADS-B Type Code value */

#define NZ                                        15.0   				  /*!< Number of latitude zones used in the CPR position decoding algorithm */
#define DLAT_EVEN                                (360.0/(4.0*NZ))    	  /*!< Latitude grid spacing (in degrees) for Even CPR frames */
#define DLAT_ODD                                (360.0/((4.0*NZ)-1.0))    /*!< Latitude grid spacing (in degrees) for Odd CPR frames */

/******************************************************************************************************************************************************************************
 * @typedef                - ADSB_StatusTypedef
 *
 * @brief                - Defines generic status values used across ADS-B data handling and decoding processes
 *
 * @Note                - This enumeration is used to describe buffer occupancy, data availability,
 *                          and error conditions in several ADS-B processing modules.
 *
 *****************************************************************************************************************************************************************************/
typedef enum
{
    ADSB_EMPTY  = 0x00U,    /*!< No data available */
    ADSB_HEMPTY = 0x01U,    /*!< Buffer partially empty */
    ADSB_HFULL  = 0x02U,    /*!< Buffer partially full */
    ADSB_FULL   = 0x03U,    /*!< Buffer full or valid data present */
    ADSB_ERROR  = 0x04U    /*!< Error condition detected */
} ADSB_StatusTypedef;

/******************************************************************************************************************************************************************************
 * @typedef                - ADSB_RingBuffStatus
 *
 * @brief                - Defines operational states of the ADS-B ring buffer
 *
 * @Note                - This enumeration is used to indicate readiness, configuration state,
 *                          and error conditions of the ADS-B ring buffer mechanism.
 *
 *****************************************************************************************************************************************************************************/
typedef enum
{
    RGBFF_NOT_READY = 0x00U,    /*!< Ring buffer not initialized or not ready */
    RGBFF_READY       = 0x01U,    /*!< Ring buffer ready for operation */
    RGBFF_ERROR       = 0x02U,    /*!< Ring buffer error condition */
    RGBFF_SET      = 0x03U,    /*!< Ring buffer or callback state set */
    RGBFF_UNSET    = 0x04U    /*!< Ring buffer or callback state unset */
} ADSB_RingBuffStatus;

/******************************************************************************************************************************************************************************
 * @struct                - ADSB_RGBuffer_t
 *
 * @brief                - Defines the ADS-B ring buffer data structure used for raw frame storage and parsing
 *
 * @Note                - This structure manages circular buffering of ADS-B raw data,
 *                          providing indexed access for sequential frame decoding.
 *
 *****************************************************************************************************************************************************************************/
typedef struct
{
    uint8_t  *buffer;    /*!< Pointer to the raw data buffer */
    uint32_t capacity;    /*!< Total buffer capacity in bytes */
    uint32_t head;        /*!< Head index for write operations */
    uint32_t tail;        /*!< Tail index for read operations */
    uint32_t count;        /*!< Number of bytes currently stored in the buffer */
    uint32_t index;        /*!< Current parsing index within the buffer */
} ADSB_RGBuffer_t;

/******************************************************************************************************************************************************************************
 * @typedef                - ADSB_FlagStatus
 *
 * @brief                - Defines a binary flag status used to indicate data availability or condition states
 *
 * @Note                - This enumeration is typically used for simple valid/invalid or present/absent
 *                          conditions within ADS-B parsing and decoding logic.
 *
 *****************************************************************************************************************************************************************************/
typedef enum
{
    EMPTY = 0U,            /*!< Flag indicates absence of data or inactive state */
    FULL  = !EMPTY        /*!< Flag indicates presence of data or active state */
} ADSB_FlagStatus;

/******************************************************************************************************************************************************************************
 * @typedef                - ADSB_FrameStatus
 *
 * @brief                - Defines validation and decoding status values for ADS-B frames
 *
 * @Note                - This enumeration is used to classify the integrity and validity of parsed ADS-B frames
 *                          throughout the decoding pipeline.
 *
 *****************************************************************************************************************************************************************************/
typedef enum
{
    EMPTY_FRAME         = 0x00U,    /*!< Frame contains no valid data */
    VALID_FRAME         = 0x01U,    /*!< Frame successfully validated and decoded */
    FRAME_OUT_OF_RANGE  = 0x02U,    /*!< Frame parameters or fields are outside valid ranges */
    INVALID_DF          = 0x03U,    /*!< Invalid or unsupported Downlink Format detected */
    INVALID_LENGHT      = 0x04U        /*!< Invalid ADS-B frame length detected */
} ADSB_FrameStatus;

/******************************************************************************************************************************************************************************
 * @struct                - ADSB_FrameStruct
 *
 * @brief                - Defines the fully decoded ADS-B frame structure
 *
 * @Note                - This structure aggregates all extracted fields from a raw ADS-B frame,
 *                          providing a single container for frame identification, message content,
 *                          and validation status.
 *
 *****************************************************************************************************************************************************************************/
typedef struct
{
    uint16_t          DownlinkFormat;    /*!< ADS-B Downlink Format (DF) value */
    uint8_t            Capability;        /*!< ADS-B Capability (CA) field */
    uint32_t            ICAOAddress;        /*!< 24-bit ICAO aircraft address */
    uint8_t              TypeCode;            /*!< ADS-B Type Code (TC) */
    uint64_t          Message;            /*!< ADS-B Message Extension (ME) field */
    uint32_t          Parity;            /*!< ADS-B Parity / CRC field */
    ADSB_FrameStatus  Status;            /*!< Decoding and validation status of the frame */
} ADSB_FrameStruct;

/******************************************************************************************************************************************************************************
 * @struct                - Frame_RGBuffer_t
 *
 * @brief                - Defines a ring buffer structure for storing decoded ADS-B frames
 *
 * @Note                - This structure manages circular storage of fully decoded ADSB_FrameStruct entries,
 *                          enabling queued frame processing and controlled access for higher-level decoding
 *                          and tracking logic.
 *
 *****************************************************************************************************************************************************************************/
typedef struct
{
    ADSB_FrameStruct *buffer;    /*!< Pointer to the buffer holding decoded ADS-B frames */
    uint32_t capacity;            /*!< Maximum number of frames the buffer can hold */
    uint32_t head;                /*!< Head index for frame insertion */
    uint32_t tail;                /*!< Tail index for frame removal */
    uint32_t count;                /*!< Current number of frames stored in the buffer */
    ADSB_RingBuffStatus status;    /*!< Current operational status of the frame ring buffer */
} Frame_RGBuffer_t;

/******************************************************************************************************************************************************************************
 * @struct                - ADSB_LocationByICAO
 *
 * @brief                - Defines a structure for storing CPR position data associated with a specific ICAO address
 *
 * @Note                - This structure encapsulates raw CPR latitude and longitude values along with frame metadata,
 *                          allowing Even and Odd CPR frames to be paired and decoded into a global aircraft position.
 *
 *****************************************************************************************************************************************************************************/
typedef struct
{
    uint32_t CPRlat;            /*!< Encoded CPR latitude value */
    uint32_t CPRlon;            /*!< Encoded CPR longitude value */
    uint32_t ICAOAddress;        /*!< 24-bit ICAO aircraft address */
    uint32_t TimeStamp;            /*!< Timestamp associated with the CPR frame reception */
    uint8_t  EvenOdd;            /*!< CPR frame format flag (0 = Even, 1 = Odd) */
    ADSB_FlagStatus Status;        /*!< Status indicating validity or availability of the CPR data */
} ADSB_LocationByICAO;


typedef struct
{
	uint32_t ICAOAddres;
	uint32_t latitude;
	uint32_t longitude;
	uint32_t bearing;
	uint8_t SystemState;
	uint8_t ReadyFlag;
	uint32_t TimeStamp;

} ADSB_TC23_MessageStruct;

/******************************************************************************************************************************************************************************
 * @struct                - ADSB_RngBuff_CPR
 *
 * @brief                - Defines a ring buffer structure for storing ADS-B CPR location frames
 *
 * @Note                - This ring buffer is used to manage Even or Odd CPR frames independently,
 *                          enabling time-correlated pairing and global CPR position decoding.
 *
 *****************************************************************************************************************************************************************************/
typedef struct
{
    ADSB_LocationByICAO *buffer;    /*!< Pointer to the buffer holding CPR location entries */
    uint32_t capacity;                /*!< Maximum number of CPR frames the buffer can hold */
    uint32_t head;                    /*!< Head index for CPR frame insertion */
    uint32_t tail;                    /*!< Tail index for CPR frame retrieval */
    uint32_t count;                    /*!< Current number of CPR frames stored */
    uint32_t index;                    /*!< Current parsing or access index within the buffer */
    ADSB_RingBuffStatus status;        /*!< Current operational status of the CPR ring buffer */
} ADSB_RngBuff_CPR;

/******************************************************************************************************************************************************************************
 * @struct                - ADSB_RngBuff_CPR
 *
 * @brief                - Defines a ring buffer structure for storing ADS-B CPR location frames
 *
 * @Note                - This ring buffer is used to manage Even or Odd CPR frames independently,
 *                          enabling time-correlated pairing and global CPR position decoding.
 *
 *****************************************************************************************************************************************************************************/
typedef struct
{
    ADSB_LocationByICAO *buffer;    /*!< Pointer to the buffer holding CPR location entries */
    uint32_t capacity;                /*!< Maximum number of CPR frames the buffer can hold */
    uint32_t head;                    /*!< Head index for CPR frame insertion */
    uint32_t tail;                    /*!< Tail index for CPR frame retrieval */
    uint32_t count;                    /*!< Current number of CPR frames stored */
    uint32_t index;                    /*!< Current parsing or access index within the buffer */
    ADSB_RingBuffStatus status;        /*!< Current operational status of the CPR ring buffer */
} ADSB_RngBuff_TC23;

/******************************************************************************************************************************************************************************
 *
 * @defgroup ADSB Functions Definitions
 *
 *****************************************************************************************************************************************************************************/
void ADSB_RingBuffer_Init(ADSB_RGBuffer_t* RingBuffer, uint8_t* Storage, uint32_t capacity);
void ADSB_RingBuffers_Init(void);
void ADSB_RingBuff_FlagSet(uint8_t HalfSelect);
void ADSB_RingBuff_FlagUnSet(uint8_t HalfSelect);
void ADSB_FrameRingBuffer_SetFlag(uint8_t DF);
void ADSB_FrameRingBuffer_UnsetFlag(uint8_t DF);
void ADSB_RingBuffer_Push(ADSB_RGBuffer_t *RingBuffer, uint8_t byte);
void ADSB_RingBuffer_PushFrame(Frame_RGBuffer_t *pRingBuffer, ADSB_FrameStruct Frame);
void ADSB_Read_HalfBuffer(ADSB_RGBuffer_t * pRingBuff, uint32_t timeStamp);
void ADSB_CPR_DecodeLocation_GlobalUnambiguousPosMethod(double EvenLat, double EvenLon, double OddLat, double OddLon, uint8_t RecentFlag,  double *pBuff);

ADSB_StatusTypedef ADSB_GetFlagStatus(void);

uint8_t ADSB_RingBuffer_Pop(ADSB_RGBuffer_t *RingBuffer);
uint8_t * ADSB_GetRGBUFF_Address(void);
uint8_t ADSB_validateDF(uint16_t DownlinkFormat);
uint8_t ADSB_Get_Instant_DF(uint8_t* pBuff);
uint8_t ADSB_Get_Instant_CA(uint8_t* pBuff);
uint8_t ADSB_Get_Instant_TC(uint8_t* pBuff);
uint8_t ADSB_CPR_DecodeLocationByICAO(ADSB_LocationByICAO CPR1, ADSB_LocationByICAO CPR2, double *pLocationBuff);

uint16_t ADSB_GetRGBUFF_Size(void);

uint32_t ADSB_Get_Instant_ICAOAdd(uint8_t* pBuff);
uint32_t ADSB_Get_Instant_PI(uint8_t* pBuff);

uint64_t ADSB_Get_Instant_ME(uint8_t* pBuff);

ADSB_LocationByICAO ADSB_CPR_Look4Odd(uint32_t ICAOadd);
ADSB_LocationByICAO ADSB_CPR_Look4Even(uint32_t ICAOadd);
ADSB_FrameStatus ADSB_GetCPR_Flag(uint64_t ME);
ADSB_FrameStruct ADSB_Read_DownlinkFormatBuffer(uint16_t downlinkFormatSelected);
ADSB_FrameStruct ADSB_DecodeFrame(ADSB_RGBuffer_t * pRingBuff, uint32_t timeStamp);
ADSB_FrameStatus ADSB_FindValidFrame(ADSB_RGBuffer_t * pRingBuff);
ADSB_FrameStruct ADSB_RingBuffer_PopFrame(Frame_RGBuffer_t *RingBuffer);

/**********************************************************************************************************************************************************************************
 *
 * @defgroup ADSB Aircraft Identification Decode Functions
 *
 *********************************************************************************************************************************************************************************/
uint8_t ADSB_ParseMessage_AirId_GetCategory(uint64_t ME);
void ADSB_ParseMessage_AirId_GetCallsign(uint64_t ME, uint8_t * pBuff);
uint8_t ADSB_ParseMessage_AirId_GetWakeVortex(uint8_t TC, uint64_t ME); // get Category to return a value.

/**********************************************************************************************************************************************************************************
 *
 * @defgroup ADSB Surface Position Decode Functions
 *
 *********************************************************************************************************************************************************************************/
uint8_t ADSB_ParseMessage_GndPos_GetGndSpeed(uint64_t ME);
uint8_t ADSB_ParseMessage_GndPos_GetStatTRK(uint64_t ME);
uint8_t ADSB_ParseMessage_GndPos_GetTRK(uint64_t ME);
uint8_t ADSB_ParseMessage_GndPos_GetTime(uint64_t ME);

uint8_t ADSB_ParseMessage_GetEvenOddF(uint64_t ME);
uint32_t ADSB_ParseMessage_GetLAT(uint64_t ME);
uint32_t ADSB_ParseMessage_GetLON(uint64_t ME);

/**********************************************************************************************************************************************************************************
 *
 * @defgroup ADSB Airborn Position (w/Baro Altitude) and (w/GNSS Altitude) Decode Functions
 *
 *********************************************************************************************************************************************************************************/
uint8_t ADSB_ParseMessage_AirPos_GetSS(uint64_t ME);
uint8_t ADSB_ParseMessage_AirPos_GetSAF(uint64_t ME);
uint16_t ADSB_ParseMessage_AirPos_GetALT_Bar(uint64_t ME);
uint16_t ADSB_ParseMessage_AirPos_GetALT_GNSS(uint64_t ME);
uint8_t ADSB_ParseMessage_AirPos_GetTime(uint64_t ME);


/*********************************************************************************************************************************************************************************
 *
 * @defgroup ADSB Airborn Velocity Decode Functions
 *
 *********************************************************************************************************************************************************************************/
uint8_t ADSB_ParseMessage_AirVel_GetST(uint64_t ME);
uint8_t ADSB_ParseMessage_AirVel_GetIC(uint64_t ME);
uint8_t ADSB_ParseMessage_AirVel_GetIFR(uint64_t ME);
uint8_t ADSB_ParseMessage_AirVel_GetNUC(uint64_t ME);

uint8_t ADSB_ParseMessage_AirVel_GetDew(uint64_t ME);
uint16_t ADSB_ParseMessage_AirVel_GetVew(uint8_t ST, uint64_t ME);
uint8_t ADSB_ParseMessage_AirVel_GetDns(uint64_t ME);
uint16_t ADSB_ParseMessage_AirVel_GetVns(uint8_t ST, uint64_t ME);

uint8_t ADSB_ParseMessage_AirVel_GetSH(uint64_t ME);
uint16_t ADSB_ParseMessage_AirVel_GetHDG(uint64_t ME);
uint8_t ADSB_ParseMessage_AirVel_GetType(uint64_t ME);
uint16_t ADSB_ParseMessage_AirVel_GetAS(uint8_t ST, uint64_t ME);

uint8_t ADSB_ParseMessage_AirVel_GetVrSrc(uint64_t ME);
uint8_t ADSB_ParseMessage_AirVel_GetSvr(uint64_t ME);
uint16_t ADSB_ParseMessage_AirVel_GetVR(uint64_t ME);
uint8_t ADSB_ParseMessage_AirVel_GetSDif(uint64_t ME);
uint8_t ADSB_ParseMessage_AirVel_GetdAlt(uint64_t ME);

/**********************************************************************************************************************************************************************************
 *
 * @defgroup ADSB Aircraft Status Decode Functions
 *
 *********************************************************************************************************************************************************************************/
uint8_t ADSB_ParseMessage_AirStatus_GetST(uint64_t ME);
uint8_t ADSB_ParseMessage_AirStatus_GetEmergency(uint64_t ME);
uint64_t ADSB_ParseMessage_AirStatus_GetACAS(uint64_t ME);

/**********************************************************************************************************************************************************************************
 *
 * @defgroup ADSB Target Status and State Decode Functions
 *
 *********************************************************************************************************************************************************************************/
uint8_t ADSB_ParseMessage_TargetSS_GetST(uint64_t ME);
uint8_t ADSB_ParseMessage_TargetSS_GetAutopilot(uint64_t ME);
uint8_t ADSB_ParseMessage_TargetSS_GetVNAV(uint64_t ME);
uint8_t ADSB_ParseMessage_TargetSS_GetAltFlg(uint64_t ME);
uint8_t ADSB_ParseMessage_TargetSS_GetApproach(uint64_t ME);
uint16_t ADSB_ParseMessage_TargetSS_GetAltSelect(uint64_t ME);
uint16_t ADSB_ParseMessage_TargetSS_GetTrackSelect(uint64_t ME);

/**********************************************************************************************************************************************************************************
 *
 * @defgroup ADSB Aircraft Operation Status Decode Functions
 *
 *********************************************************************************************************************************************************************************/
uint8_t ADSB_ParseMessage_AirOpStat_GetST(uint64_t ME);
uint8_t ADSB_ParseMessage_AirOpStat_GetCC4(uint64_t ME);
uint8_t ADSB_ParseMessage_AirOpStat_GetCC3(uint64_t ME);
uint8_t ADSB_ParseMessage_AirOpStat_GetCC2(uint64_t ME);
uint8_t ADSB_ParseMessage_AirOpStat_GetCC1(uint64_t ME);
uint8_t ADSB_ParseMessage_AirOpStat_GetOM4(uint64_t ME);
uint8_t ADSB_ParseMessage_AirOpStat_GetOM3(uint64_t ME);
uint8_t ADSB_ParseMessage_AirOpStat_GetOM2(uint64_t ME);
uint8_t ADSB_ParseMessage_AirOpStat_GetOM1(uint64_t ME);


uint32_t ADSB_CalculateCRC24(const uint8_t *data, uint32_t numDataBits);

#endif /* ADSB_DRIVER_ADSB_DRIVER_H_ */
