int R[2000] = { 32766, 0, 32765, 206, 32763, 412, 32760, 618, 32756, 823, 32750, 1029, 32743, 1235, 32734, 1441, 32725, 1646, 32714, 1852, 32701, 2057, 32688, 2263, 32673, 2468, 32657, 2673, 32639, 2879, 32621, 3084, 32601, 3288, 32579, 3493, 32557, 3698, 32533, 3902, 32508, 4107, 32481, 4311, 32453, 4515, 32424, 4719, 32394, 4922, 32363, 5126, 32330, 5329, 32296, 5532, 32260, 5735, 32224, 5937, 32186, 6140, 32146, 6342, 32106, 6544, 32064, 6745, 32021, 6947, 31977, 7148, 31931, 7348, 31885, 7549, 31836, 7749, 31787, 7949, 31737, 8149, 31685, 8348, 31632, 8547, 31577, 8745, 31522, 8944, 31465, 9141, 31407, 9339, 31348, 9536, 31287, 9733, 31225, 9929, 31162, 10125, 31098, 10321, 31033, 10516, 30966, 10711, 30898, 10905, 30829, 11099, 30759, 11293, 30687, 11486, 30614, 11678, 30540, 11870, 30465, 12062, 30389, 12253, 30311, 12444, 30232, 12634, 30152, 12824, 30071, 13013, 29989, 13202, 29905, 13390, 29821, 13577, 29735, 13765, 29648, 13951, 29559, 14137, 29470, 14323, 29379, 14507, 29288, 14692, 29195, 14875, 29101, 15059, 29005, 15241, 28909, 15423, 28812, 15604, 28713, 15785, 28613, 15965, 28512, 16145, 28410, 16324, 28307, 16502, 28203, 16679, 28098, 16856, 27991, 17032, 27884, 17208, 27775, 17383, 27665, 17557, 27554, 17730, 27442, 17903, 27329, 18075, 27215, 18247, 27100, 18417, 26984, 18587, 26867, 18756, 26748, 18925, 26629, 19092, 26508, 19259, 26387, 19426, 26264, 19591, 26141, 19756, 26016, 19919, 25890, 20083, 25764, 20245, 25636, 20406, 25507, 20567, 25377, 20727, 25247, 20886, 25115, 21044, 24982, 21201, 24848, 21358, 24714, 21514, 24578, 21669, 24442, 21823, 24304, 21976, 24165, 22128, 24026, 22279, 23885, 22430, 23744, 22580, 23602, 22728, 23458, 22876, 23314, 23023, 23169, 23169, 23023, 23314, 22876, 23458, 22728, 23602, 22580, 23744, 22430, 23885, 22279, 24026, 22128, 24165, 21976, 24304, 21823, 24442, 21669, 24578, 21514, 24714, 21358, 24848, 21201, 24982, 21044, 25115, 20886, 25247, 20727, 25377, 20567, 25507, 20406, 25636, 20245, 25764, 20083, 25890, 19919, 26016, 19756, 26141, 19591, 26264, 19426, 26387, 19259, 26508, 19092, 26629, 18925, 26748, 18756, 26867, 18587, 26984, 18417, 27100, 18247, 27215, 18075, 27329, 17903, 27442, 17730, 27554, 17557, 27665, 17383, 27775, 17208, 27884, 17032, 27991, 16856, 28098, 16679, 28203, 16502, 28307, 16324, 28410, 16145, 28512, 15965, 28613, 15785, 28713, 15604, 28812, 15423, 28909, 15241, 29005, 15059, 29101, 14875, 29195, 14692, 29288, 14507, 29379, 14323, 29470, 14137, 29559, 13951, 29648, 13765, 29735, 13577, 29821, 13390, 29905, 13202, 29989, 13013, 30071, 12824, 30152, 12634, 30232, 12444, 30311, 12253, 30389, 12062, 30465, 11870, 30540, 11678, 30614, 11486, 30687, 11293, 30759, 11099, 30829, 10905, 30898, 10711, 30966, 10516, 31033, 10321, 31098, 10125, 31162, 9929, 31225, 9733, 31287, 9536, 31348, 9339, 31407, 9141, 31465, 8944, 31522, 8745, 31577, 8547, 31632, 8348, 31685, 8149, 31737, 7949, 31787, 7749, 31836, 7549, 31885, 7348, 31931, 7148, 31977, 6947, 32021, 6745, 32064, 6544, 32106, 6342, 32146, 6140, 32186, 5937, 32224, 5735, 32260, 5532, 32296, 5329, 32330, 5126, 32363, 4922, 32394, 4719, 32424, 4515, 32453, 4311, 32481, 4107, 32508, 3902, 32533, 3698, 32557, 3493, 32579, 3288, 32601, 3084, 32621, 2879, 32639, 2673, 32657, 2468, 32673, 2263, 32688, 2057, 32701, 1852, 32714, 1646, 32725, 1441, 32734, 1235, 32743, 1029, 32750, 823, 32756, 618, 32760, 412, 32763, 206, 32765, 0, 32766, -206, 32765, -412, 32763, -618, 32760, -823, 32756, -1029, 32750, -1235, 32743, -1441, 32734, -1646, 32725, -1852, 32714, -2057, 32701, -2263, 32688, -2468, 32673, -2673, 32657, -2879, 32639, -3084, 32621, -3288, 32601, -3493, 32579, -3698, 32557, -3902, 32533, -4107, 32508, -4311, 32481, -4515, 32453, -4719, 32424, -4922, 32394, -5126, 32363, -5329, 32330, -5532, 32296, -5735, 32260, -5937, 32224, -6140, 32186, -6342, 32146, -6544, 32106, -6745, 32064, -6947, 32021, -7148, 31977, -7348, 31931, -7549, 31885, -7749, 31836, -7949, 31787, -8149, 31737, -8348, 31685, -8547, 31632, -8745, 31577, -8944, 31522, -9141, 31465, -9339, 31407, -9536, 31348, -9733, 31287, -9929, 31225, -10125, 31162, -10321, 31098, -10516, 31033, -10711, 30966, -10905, 30898, -11099, 30829, -11293, 30759, -11486, 30687, -11678, 30614, -11870, 30540, -12062, 30465, -12253, 30389, -12444, 30311, -12634, 30232, -12824, 30152, -13013, 30071, -13202, 29989, -13390, 29905, -13577, 29821, -13765, 29735, -13951, 29648, -14137, 29559, -14323, 29470, -14507, 29379, -14692, 29288, -14875, 29195, -15059, 29101, -15241, 29005, -15423, 28909, -15604, 28812, -15785, 28713, -15965, 28613, -16145, 28512, -16324, 28410, -16502, 28307, -16679, 28203, -16856, 28098, -17032, 27991, -17208, 27884, -17383, 27775, -17557, 27665, -17730, 27554, -17903, 27442, -18075, 27329, -18247, 27215, -18417, 27100, -18587, 26984, -18756, 26867, -18925, 26748, -19092, 26629, -19259, 26508, -19426, 26387, -19591, 26264, -19756, 26141, -19919, 26016, -20083, 25890, -20245, 25764, -20406, 25636, -20567, 25507, -20727, 25377, -20886, 25247, -21044, 25115, -21201, 24982, -21358, 24848, -21514, 24714, -21669, 24578, -21823, 24442, -21976, 24304, -22128, 24165, -22279, 24026, -22430, 23885, -22580, 23744, -22728, 23602, -22876, 23458, -23023, 23314, -23169, 23169, -23314, 23023, -23458, 22876, -23602, 22728, -23744, 22580, -23885, 22430, -24026, 22279, -24165, 22128, -24304, 21976, -24442, 21823, -24578, 21669, -24714, 21514, -24848, 21358, -24982, 21201, -25115, 21044, -25247, 20886, -25377, 20727, -25507, 20567, -25636, 20406, -25764, 20245, -25890, 20083, -26016, 19919, -26141, 19756, -26264, 19591, -26387, 19426, -26508, 19259, -26629, 19092, -26748, 18925, -26867, 18756, -26984, 18587, -27100, 18417, -27215, 18247, -27329, 18075, -27442, 17903, -27554, 17730, -27665, 17557, -27775, 17383, -27884, 17208, -27991, 17032, -28098, 16856, -28203, 16679, -28307, 16502, -28410, 16324, -28512, 16145, -28613, 15965, -28713, 15785, -28812, 15604, -28909, 15423, -29005, 15241, -29101, 15059, -29195, 14875, -29288, 14692, -29379, 14507, -29470, 14323, -29559, 14137, -29648, 13951, -29735, 13765, -29821, 13577, -29905, 13390, -29989, 13202, -30071, 13013, -30152, 12824, -30232, 12634, -30311, 12444, -30389, 12253, -30465, 12062, -30540, 11870, -30614, 11678, -30687, 11486, -30759, 11293, -30829, 11099, -30898, 10905, -30966, 10711, -31033, 10516, -31098, 10321, -31162, 10125, -31225, 9929, -31287, 9733, -31348, 9536, -31407, 9339, -31465, 9141, -31522, 8944, -31577, 8745, -31632, 8547, -31685, 8348, -31737, 8149, -31787, 7949, -31836, 7749, -31885, 7549, -31931, 7348, -31977, 7148, -32021, 6947, -32064, 6745, -32106, 6544, -32146, 6342, -32186, 6140, -32224, 5937, -32260, 5735, -32296, 5532, -32330, 5329, -32363, 5126, -32394, 4922, -32424, 4719, -32453, 4515, -32481, 4311, -32508, 4107, -32533, 3902, -32557, 3698, -32579, 3493, -32601, 3288, -32621, 3084, -32639, 2879, -32657, 2673, -32673, 2468, -32688, 2263, -32701, 2057, -32714, 1852, -32725, 1646, -32734, 1441, -32743, 1235, -32750, 1029, -32756, 823, -32760, 618, -32763, 412, -32765, 206, -32766, 0, -32765, -206, -32763, -412, -32760, -618, -32756, -823, -32750, -1029, -32743, -1235, -32734, -1441, -32725, -1646, -32714, -1852, -32701, -2057, -32688, -2263, -32673, -2468, -32657, -2673, -32639, -2879, -32621, -3084, -32601, -3288, -32579, -3493, -32557, -3698, -32533, -3902, -32508, -4107, -32481, -4311, -32453, -4515, -32424, -4719, -32394, -4922, -32363, -5126, -32330, -5329, -32296, -5532, -32260, -5735, -32224, -5937, -32186, -6140, -32146, -6342, -32106, -6544, -32064, -6745, -32021, -6947, -31977, -7148, -31931, -7348, -31885, -7549, -31836, -7749, -31787, -7949, -31737, -8149, -31685, -8348, -31632, -8547, -31577, -8745, -31522, -8944, -31465, -9141, -31407, -9339, -31348, -9536, -31287, -9733, -31225, -9929, -31162, -10125, -31098, -10321, -31033, -10516, -30966, -10711, -30898, -10905, -30829, -11099, -30759, -11293, -30687, -11486, -30614, -11678, -30540, -11870, -30465, -12062, -30389, -12253, -30311, -12444, -30232, -12634, -30152, -12824, -30071, -13013, -29989, -13202, -29905, -13390, -29821, -13577, -29735, -13765, -29648, -13951, -29559, -14137, -29470, -14323, -29379, -14507, -29288, -14692, -29195, -14875, -29101, -15059, -29005, -15241, -28909, -15423, -28812, -15604, -28713, -15785, -28613, -15965, -28512, -16145, -28410, -16324, -28307, -16502, -28203, -16679, -28098, -16856, -27991, -17032, -27884, -17208, -27775, -17383, -27665, -17557, -27554, -17730, -27442, -17903, -27329, -18075, -27215, -18247, -27100, -18417, -26984, -18587, -26867, -18756, -26748, -18925, -26629, -19092, -26508, -19259, -26387, -19426, -26264, -19591, -26141, -19756, -26016, -19919, -25890, -20083, -25764, -20245, -25636, -20406, -25507, -20567, -25377, -20727, -25247, -20886, -25115, -21044, -24982, -21201, -24848, -21358, -24714, -21514, -24578, -21669, -24442, -21823, -24304, -21976, -24165, -22128, -24026, -22279, -23885, -22430, -23744, -22580, -23602, -22728, -23458, -22876, -23314, -23023, -23169, -23169, -23023, -23314, -22876, -23458, -22728, -23602, -22580, -23744, -22430, -23885, -22279, -24026, -22128, -24165, -21976, -24304, -21823, -24442, -21669, -24578, -21514, -24714, -21358, -24848, -21201, -24982, -21044, -25115, -20886, -25247, -20727, -25377, -20567, -25507, -20406, -25636, -20245, -25764, -20083, -25890, -19919, -26016, -19756, -26141, -19591, -26264, -19426, -26387, -19259, -26508, -19092, -26629, -18925, -26748, -18756, -26867, -18587, -26984, -18417, -27100, -18247, -27215, -18075, -27329, -17903, -27442, -17730, -27554, -17557, -27665, -17383, -27775, -17208, -27884, -17032, -27991, -16856, -28098, -16679, -28203, -16502, -28307, -16324, -28410, -16145, -28512, -15965, -28613, -15785, -28713, -15604, -28812, -15423, -28909, -15241, -29005, -15059, -29101, -14875, -29195, -14692, -29288, -14507, -29379, -14323, -29470, -14137, -29559, -13951, -29648, -13765, -29735, -13577, -29821, -13390, -29905, -13202, -29989, -13013, -30071, -12824, -30152, -12634, -30232, -12444, -30311, -12253, -30389, -12062, -30465, -11870, -30540, -11678, -30614, -11486, -30687, -11293, -30759, -11099, -30829, -10905, -30898, -10711, -30966, -10516, -31033, -10321, -31098, -10125, -31162, -9929, -31225, -9733, -31287, -9536, -31348, -9339, -31407, -9141, -31465, -8944, -31522, -8745, -31577, -8547, -31632, -8348, -31685, -8149, -31737, -7949, -31787, -7749, -31836, -7549, -31885, -7348, -31931, -7148, -31977, -6947, -32021, -6745, -32064, -6544, -32106, -6342, -32146, -6140, -32186, -5937, -32224, -5735, -32260, -5532, -32296, -5329, -32330, -5126, -32363, -4922, -32394, -4719, -32424, -4515, -32453, -4311, -32481, -4107, -32508, -3902, -32533, -3698, -32557, -3493, -32579, -3288, -32601, -3084, -32621, -2879, -32639, -2673, -32657, -2468, -32673, -2263, -32688, -2057, -32701, -1852, -32714, -1646, -32725, -1441, -32734, -1235, -32743, -1029, -32750, -823, -32756, -618, -32760, -412, -32763, -206, -32765, 0, -32766, 206, -32765, 412, -32763, 618, -32760, 823, -32756, 1029, -32750, 1235, -32743, 1441, -32734, 1646, -32725, 1852, -32714, 2057, -32701, 2263, -32688, 2468, -32673, 2673, -32657, 2879, -32639, 3084, -32621, 3288, -32601, 3493, -32579, 3698, -32557, 3902, -32533, 4107, -32508, 4311, -32481, 4515, -32453, 4719, -32424, 4922, -32394, 5126, -32363, 5329, -32330, 5532, -32296, 5735, -32260, 5937, -32224, 6140, -32186, 6342, -32146, 6544, -32106, 6745, -32064, 6947, -32021, 7148, -31977, 7348, -31931, 7549, -31885, 7749, -31836, 7949, -31787, 8149, -31737, 8348, -31685, 8547, -31632, 8745, -31577, 8944, -31522, 9141, -31465, 9339, -31407, 9536, -31348, 9733, -31287, 9929, -31225, 10125, -31162, 10321, -31098, 10516, -31033, 10711, -30966, 10905, -30898, 11099, -30829, 11293, -30759, 11486, -30687, 11678, -30614, 11870, -30540, 12062, -30465, 12253, -30389, 12444, -30311, 12634, -30232, 12824, -30152, 13013, -30071, 13202, -29989, 13390, -29905, 13577, -29821, 13765, -29735, 13951, -29648, 14137, -29559, 14323, -29470, 14507, -29379, 14692, -29288, 14875, -29195, 15059, -29101, 15241, -29005, 15423, -28909, 15604, -28812, 15785, -28713, 15965, -28613, 16145, -28512, 16324, -28410, 16502, -28307, 16679, -28203, 16856, -28098, 17032, -27991, 17208, -27884, 17383, -27775, 17557, -27665, 17730, -27554, 17903, -27442, 18075, -27329, 18247, -27215, 18417, -27100, 18587, -26984, 18756, -26867, 18925, -26748, 19092, -26629, 19259, -26508, 19426, -26387, 19591, -26264, 19756, -26141, 19919, -26016, 20083, -25890, 20245, -25764, 20406, -25636, 20567, -25507, 20727, -25377, 20886, -25247, 21044, -25115, 21201, -24982, 21358, -24848, 21514, -24714, 21669, -24578, 21823, -24442, 21976, -24304, 22128, -24165, 22279, -24026, 22430, -23885, 22580, -23744, 22728, -23602, 22876, -23458, 23023, -23314, 23169, -23169, 23314, -23023, 23458, -22876, 23602, -22728, 23744, -22580, 23885, -22430, 24026, -22279, 24165, -22128, 24304, -21976, 24442, -21823, 24578, -21669, 24714, -21514, 24848, -21358, 24982, -21201, 25115, -21044, 25247, -20886, 25377, -20727, 25507, -20567, 25636, -20406, 25764, -20245, 25890, -20083, 26016, -19919, 26141, -19756, 26264, -19591, 26387, -19426, 26508, -19259, 26629, -19092, 26748, -18925, 26867, -18756, 26984, -18587, 27100, -18417, 27215, -18247, 27329, -18075, 27442, -17903, 27554, -17730, 27665, -17557, 27775, -17383, 27884, -17208, 27991, -17032, 28098, -16856, 28203, -16679, 28307, -16502, 28410, -16324, 28512, -16145, 28613, -15965, 28713, -15785, 28812, -15604, 28909, -15423, 29005, -15241, 29101, -15059, 29195, -14875, 29288, -14692, 29379, -14507, 29470, -14323, 29559, -14137, 29648, -13951, 29735, -13765, 29821, -13577, 29905, -13390, 29989, -13202, 30071, -13013, 30152, -12824, 30232, -12634, 30311, -12444, 30389, -12253, 30465, -12062, 30540, -11870, 30614, -11678, 30687, -11486, 30759, -11293, 30829, -11099, 30898, -10905, 30966, -10711, 31033, -10516, 31098, -10321, 31162, -10125, 31225, -9929, 31287, -9733, 31348, -9536, 31407, -9339, 31465, -9141, 31522, -8944, 31577, -8745, 31632, -8547, 31685, -8348, 31737, -8149, 31787, -7949, 31836, -7749, 31885, -7549, 31931, -7348, 31977, -7148, 32021, -6947, 32064, -6745, 32106, -6544, 32146, -6342, 32186, -6140, 32224, -5937, 32260, -5735, 32296, -5532, 32330, -5329, 32363, -5126, 32394, -4922, 32424, -4719, 32453, -4515, 32481, -4311, 32508, -4107, 32533, -3902, 32557, -3698, 32579, -3493, 32601, -3288, 32621, -3084, 32639, -2879, 32657, -2673, 32673, -2468, 32688, -2263, 32701, -2057, 32714, -1852, 32725, -1646, 32734, -1441, 32743, -1235, 32750, -1029, 32756, -823, 32760, -618, 32763, -412, 32765, -206};
#define DC_gainR 16383
