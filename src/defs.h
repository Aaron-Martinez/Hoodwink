#ifndef DEFS_H
#define DEFS_H

#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed ", #n); \
printf("On %s ", __DATE__); \
printf("At %s ", __TIME__); \
printf("In File %s ", __FILE__); \
printf("At Line %d\n", __LINE__); \
exit(1);}

#endif


#define BRD_NUM_SQ 120
#define MAXMOVES 2048
#define START_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"


#include <iostream>
#include <cstdlib>

typedef unsigned long long U64;

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };
enum { WHITE, BLACK, BOTH };

// may use this depending on move representation details
//enum { PROMOTED_KNIGHT = 1, PROMOTED_BISHOP = 2, PROMOTED_ROOK = 4, PROMOTED_QUEEN = 8};

// castling rights
enum { W_OO = 1, W_OOO = 2, B_OO = 4, B_OOO = 8 };

// 120 index chess board
enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2, 
    A3 = 41, B3, C3, D3, E3, F3, G3, H3, 
    A4 = 51, B4, C4, D4, E4, F4, G4, H4, 
    A5 = 61, B5, C5, D5, E5, F5, G5, H5, 
    A6 = 71, B6, C6, D6, E6, F6, G6, H6, 
    A7 = 81, B7, C7, D7, E7, F7, G7, H7, 
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ, OFFBOARD
};

extern int index120to64[BRD_NUM_SQ];
extern int index64to120[64];

extern int isPieceN[13];
extern int isPieceK[13];
extern int isPieceRQ[13];
extern int isPieceBQ[13];

extern int isPieceBig[13];
extern int isPieceMaj[13];
extern int isPieceMin[13];
extern int pieceValue[13];
extern int pieceColor[13];


extern int filesArr[BRD_NUM_SQ];
extern int ranksArr[BRD_NUM_SQ];

// move flag bit masks
extern const int moveFlagEP;
extern const int moveFlagPawnDouble;
extern const int moveFlagCastles;
extern const int moveFlagIsCapture;
extern const int moveFlagIsPromote;

struct MoveHistory {
    int move;
    int castleRights;
    int enPas;
    int fiftyMove;
    U64 posKey;
};


#endif