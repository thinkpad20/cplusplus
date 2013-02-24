#include <iostream>
#include <thread>
#include <mutex>

using std::thread;
using std::mutex;
using std::lock_guard;
using std::cout;
using std::endl;

int i=0;
mutex i_mutex;

void func() {
	lock_guard<mutex> guard(i_mutex);
	++i;
	cout << "Thread no." << std::this_thread::get_id() << " changed i to " << i << endl;
}

void countUp() {
	for (int i=0; i<100; ++i) {
		func();
	}
}

int main() {
	thread t1(countUp), t2(countUp), t3(countUp);
	t1.join();
	t2.join();
	t3.join();
	return 0;
}

/* TRANSCRIPT: 

Thread no.0x1000c0000 changed i to 1
Thread no.0x100381000 changed i to 2
Thread no.0x100404000 changed i to 3
Thread no.0x1000c0000 changed i to 4
Thread no.0x100381000 changed i to 5
Thread no.0x100404000 changed i to 6
Thread no.0x1000c0000 changed i to 7
Thread no.0x100381000 changed i to 8
Thread no.0x100404000 changed i to 9
Thread no.0x1000c0000 changed i to 10
Thread no.0x100381000 changed i to 11
Thread no.0x100404000 changed i to 12
Thread no.0x1000c0000 changed i to 13
Thread no.0x100381000 changed i to 14
Thread no.0x100404000 changed i to 15
Thread no.0x1000c0000 changed i to 16
Thread no.0x100381000 changed i to 17
Thread no.0x100404000 changed i to 18
Thread no.0x1000c0000 changed i to 19
Thread no.0x100381000 changed i to 20
Thread no.0x100404000 changed i to 21
Thread no.0x1000c0000 changed i to 22
Thread no.0x100381000 changed i to 23
Thread no.0x100404000 changed i to 24
Thread no.0x1000c0000 changed i to 25
Thread no.0x100381000 changed i to 26
Thread no.0x100404000 changed i to 27
Thread no.0x1000c0000 changed i to 28
Thread no.0x100381000 changed i to 29
Thread no.0x100404000 changed i to 30
Thread no.0x1000c0000 changed i to 31
Thread no.0x100381000 changed i to 32
Thread no.0x100404000 changed i to 33
Thread no.0x1000c0000 changed i to 34
Thread no.0x100381000 changed i to 35
Thread no.0x100404000 changed i to 36
Thread no.0x1000c0000 changed i to 37
Thread no.0x100381000 changed i to 38
Thread no.0x100404000 changed i to 39
Thread no.0x1000c0000 changed i to 40
Thread no.0x100381000 changed i to 41
Thread no.0x100404000 changed i to 42
Thread no.0x1000c0000 changed i to 43
Thread no.0x100381000 changed i to 44
Thread no.0x100404000 changed i to 45
Thread no.0x1000c0000 changed i to 46
Thread no.0x100381000 changed i to 47
Thread no.0x100404000 changed i to 48
Thread no.0x1000c0000 changed i to 49
Thread no.0x100381000 changed i to 50
Thread no.0x100404000 changed i to 51
Thread no.0x1000c0000 changed i to 52
Thread no.0x100381000 changed i to 53
Thread no.0x100404000 changed i to 54
Thread no.0x1000c0000 changed i to 55
Thread no.0x100381000 changed i to 56
Thread no.0x100404000 changed i to 57
Thread no.0x1000c0000 changed i to 58
Thread no.0x100381000 changed i to 59
Thread no.0x100404000 changed i to 60
Thread no.0x1000c0000 changed i to 61
Thread no.0x100381000 changed i to 62
Thread no.0x100404000 changed i to 63
Thread no.0x1000c0000 changed i to 64
Thread no.0x100381000 changed i to 65
Thread no.0x100404000 changed i to 66
Thread no.0x1000c0000 changed i to 67
Thread no.0x100381000 changed i to 68
Thread no.0x100404000 changed i to 69
Thread no.0x1000c0000 changed i to 70
Thread no.0x100404000 changed i to 71
Thread no.0x100381000 changed i to 72
Thread no.0x1000c0000 changed i to 73
Thread no.0x100404000 changed i to 74
Thread no.0x100381000 changed i to 75
Thread no.0x1000c0000 changed i to 76
Thread no.0x100404000 changed i to 77
Thread no.0x100381000 changed i to 78
Thread no.0x1000c0000 changed i to 79
Thread no.0x100404000 changed i to 80
Thread no.0x100381000 changed i to 81
Thread no.0x1000c0000 changed i to 82
Thread no.0x100404000 changed i to 83
Thread no.0x100381000 changed i to 84
Thread no.0x1000c0000 changed i to 85
Thread no.0x100404000 changed i to 86
Thread no.0x100381000 changed i to 87
Thread no.0x1000c0000 changed i to 88
Thread no.0x100404000 changed i to 89
Thread no.0x100381000 changed i to 90
Thread no.0x1000c0000 changed i to 91
Thread no.0x100404000 changed i to 92
Thread no.0x100381000 changed i to 93
Thread no.0x1000c0000 changed i to 94
Thread no.0x100404000 changed i to 95
Thread no.0x100381000 changed i to 96
Thread no.0x1000c0000 changed i to 97
Thread no.0x100404000 changed i to 98
Thread no.0x100381000 changed i to 99
Thread no.0x1000c0000 changed i to 100
Thread no.0x100404000 changed i to 101
Thread no.0x100381000 changed i to 102
Thread no.0x1000c0000 changed i to 103
Thread no.0x100404000 changed i to 104
Thread no.0x100381000 changed i to 105
Thread no.0x1000c0000 changed i to 106
Thread no.0x100404000 changed i to 107
Thread no.0x100381000 changed i to 108
Thread no.0x1000c0000 changed i to 109
Thread no.0x100404000 changed i to 110
Thread no.0x100381000 changed i to 111
Thread no.0x1000c0000 changed i to 112
Thread no.0x100404000 changed i to 113
Thread no.0x100381000 changed i to 114
Thread no.0x1000c0000 changed i to 115
Thread no.0x100404000 changed i to 116
Thread no.0x100381000 changed i to 117
Thread no.0x1000c0000 changed i to 118
Thread no.0x100404000 changed i to 119
Thread no.0x100381000 changed i to 120
Thread no.0x1000c0000 changed i to 121
Thread no.0x100404000 changed i to 122
Thread no.0x100381000 changed i to 123
Thread no.0x1000c0000 changed i to 124
Thread no.0x100404000 changed i to 125
Thread no.0x100381000 changed i to 126
Thread no.0x1000c0000 changed i to 127
Thread no.0x100404000 changed i to 128
Thread no.0x100381000 changed i to 129
Thread no.0x1000c0000 changed i to 130
Thread no.0x100404000 changed i to 131
Thread no.0x100381000 changed i to 132
Thread no.0x1000c0000 changed i to 133
Thread no.0x100404000 changed i to 134
Thread no.0x100381000 changed i to 135
Thread no.0x1000c0000 changed i to 136
Thread no.0x100404000 changed i to 137
Thread no.0x100381000 changed i to 138
Thread no.0x1000c0000 changed i to 139
Thread no.0x100404000 changed i to 140
Thread no.0x100381000 changed i to 141
Thread no.0x1000c0000 changed i to 142
Thread no.0x100404000 changed i to 143
Thread no.0x100381000 changed i to 144
Thread no.0x1000c0000 changed i to 145
Thread no.0x100404000 changed i to 146
Thread no.0x100381000 changed i to 147
Thread no.0x1000c0000 changed i to 148
Thread no.0x100404000 changed i to 149
Thread no.0x100381000 changed i to 150
Thread no.0x1000c0000 changed i to 151
Thread no.0x100404000 changed i to 152
Thread no.0x100381000 changed i to 153
Thread no.0x1000c0000 changed i to 154
Thread no.0x100404000 changed i to 155
Thread no.0x100381000 changed i to 156
Thread no.0x1000c0000 changed i to 157
Thread no.0x100404000 changed i to 158
Thread no.0x100381000 changed i to 159
Thread no.0x1000c0000 changed i to 160
Thread no.0x100404000 changed i to 161
Thread no.0x100381000 changed i to 162
Thread no.0x1000c0000 changed i to 163
Thread no.0x100404000 changed i to 164
Thread no.0x100381000 changed i to 165
Thread no.0x1000c0000 changed i to 166
Thread no.0x100404000 changed i to 167
Thread no.0x100381000 changed i to 168
Thread no.0x1000c0000 changed i to 169
Thread no.0x100404000 changed i to 170
Thread no.0x100381000 changed i to 171
Thread no.0x1000c0000 changed i to 172
Thread no.0x100404000 changed i to 173
Thread no.0x100381000 changed i to 174
Thread no.0x100404000 changed i to 175
Thread no.0x100381000 changed i to 176
Thread no.0x1000c0000 changed i to 177
Thread no.0x100404000 changed i to 178
Thread no.0x100381000 changed i to 179
Thread no.0x1000c0000 changed i to 180
Thread no.0x100404000 changed i to 181
Thread no.0x100381000 changed i to 182
Thread no.0x1000c0000 changed i to 183
Thread no.0x100404000 changed i to 184
Thread no.0x100381000 changed i to 185
Thread no.0x1000c0000 changed i to 186
Thread no.0x100404000 changed i to 187
Thread no.0x100381000 changed i to 188
Thread no.0x1000c0000 changed i to 189
Thread no.0x100404000 changed i to 190
Thread no.0x100381000 changed i to 191
Thread no.0x1000c0000 changed i to 192
Thread no.0x100404000 changed i to 193
Thread no.0x100381000 changed i to 194
Thread no.0x1000c0000 changed i to 195
Thread no.0x100404000 changed i to 196
Thread no.0x100381000 changed i to 197
Thread no.0x1000c0000 changed i to 198
Thread no.0x100404000 changed i to 199
Thread no.0x100381000 changed i to 200
Thread no.0x1000c0000 changed i to 201
Thread no.0x100404000 changed i to 202
Thread no.0x100381000 changed i to 203
Thread no.0x1000c0000 changed i to 204
Thread no.0x100404000 changed i to 205
Thread no.0x100381000 changed i to 206
Thread no.0x1000c0000 changed i to 207
Thread no.0x100404000 changed i to 208
Thread no.0x100381000 changed i to 209
Thread no.0x1000c0000 changed i to 210
Thread no.0x100404000 changed i to 211
Thread no.0x100381000 changed i to 212
Thread no.0x1000c0000 changed i to 213
Thread no.0x100404000 changed i to 214
Thread no.0x100381000 changed i to 215
Thread no.0x1000c0000 changed i to 216
Thread no.0x100404000 changed i to 217
Thread no.0x100381000 changed i to 218
Thread no.0x1000c0000 changed i to 219
Thread no.0x100404000 changed i to 220
Thread no.0x100381000 changed i to 221
Thread no.0x1000c0000 changed i to 222
Thread no.0x100404000 changed i to 223
Thread no.0x100381000 changed i to 224
Thread no.0x1000c0000 changed i to 225
Thread no.0x100404000 changed i to 226
Thread no.0x100381000 changed i to 227
Thread no.0x1000c0000 changed i to 228
Thread no.0x100404000 changed i to 229
Thread no.0x100381000 changed i to 230
Thread no.0x1000c0000 changed i to 231
Thread no.0x100404000 changed i to 232
Thread no.0x100381000 changed i to 233
Thread no.0x1000c0000 changed i to 234
Thread no.0x100404000 changed i to 235
Thread no.0x100381000 changed i to 236
Thread no.0x1000c0000 changed i to 237
Thread no.0x100404000 changed i to 238
Thread no.0x100381000 changed i to 239
Thread no.0x1000c0000 changed i to 240
Thread no.0x100404000 changed i to 241
Thread no.0x100381000 changed i to 242
Thread no.0x1000c0000 changed i to 243
Thread no.0x100404000 changed i to 244
Thread no.0x100381000 changed i to 245
Thread no.0x1000c0000 changed i to 246
Thread no.0x100404000 changed i to 247
Thread no.0x100381000 changed i to 248
Thread no.0x1000c0000 changed i to 249
Thread no.0x100404000 changed i to 250
Thread no.0x100381000 changed i to 251
Thread no.0x1000c0000 changed i to 252
Thread no.0x100404000 changed i to 253
Thread no.0x100381000 changed i to 254
Thread no.0x1000c0000 changed i to 255
Thread no.0x100404000 changed i to 256
Thread no.0x100381000 changed i to 257
Thread no.0x1000c0000 changed i to 258
Thread no.0x100404000 changed i to 259
Thread no.0x100381000 changed i to 260
Thread no.0x1000c0000 changed i to 261
Thread no.0x100404000 changed i to 262
Thread no.0x100381000 changed i to 263
Thread no.0x1000c0000 changed i to 264
Thread no.0x100404000 changed i to 265
Thread no.0x100381000 changed i to 266
Thread no.0x1000c0000 changed i to 267
Thread no.0x100404000 changed i to 268
Thread no.0x100381000 changed i to 269
Thread no.0x1000c0000 changed i to 270
Thread no.0x100404000 changed i to 271
Thread no.0x100381000 changed i to 272
Thread no.0x1000c0000 changed i to 273
Thread no.0x100404000 changed i to 274
Thread no.0x100381000 changed i to 275
Thread no.0x1000c0000 changed i to 276
Thread no.0x100404000 changed i to 277
Thread no.0x100381000 changed i to 278
Thread no.0x1000c0000 changed i to 279
Thread no.0x100404000 changed i to 280
Thread no.0x100381000 changed i to 281
Thread no.0x1000c0000 changed i to 282
Thread no.0x100404000 changed i to 283
Thread no.0x100381000 changed i to 284
Thread no.0x1000c0000 changed i to 285
Thread no.0x100404000 changed i to 286
Thread no.0x100381000 changed i to 287
Thread no.0x1000c0000 changed i to 288
Thread no.0x100404000 changed i to 289
Thread no.0x100381000 changed i to 290
Thread no.0x1000c0000 changed i to 291
Thread no.0x100404000 changed i to 292
Thread no.0x100381000 changed i to 293
Thread no.0x1000c0000 changed i to 294
Thread no.0x100404000 changed i to 295
Thread no.0x100381000 changed i to 296
Thread no.0x1000c0000 changed i to 297
Thread no.0x100404000 changed i to 298
Thread no.0x100381000 changed i to 299
Thread no.0x1000c0000 changed i to 300

*/