/*
 *  Record/replay functions of Chromium's base/record_replay.h, which WebRTC's
 *  own build can't include. Chromium is recording or replaying its own run
 *  when IsRecordingOrReplaying says so.
 */

#ifndef RTC_BASE_RECORD_REPLAY_H_
#define RTC_BASE_RECORD_REPLAY_H_

#include <stddef.h>
#include <stdint.h>

namespace recordreplay {
bool IsRecordingOrReplaying(const char* feature, const char* subfeature);
uintptr_t RecordReplayValue(const char* why, uintptr_t v);
void RecordReplayBytes(const char* why, void* buf, size_t size);
// Checked when replaying against what the recording had here.
void Assert(const char* format, ...);
void AssertBytes(const char* why, const void* buf, size_t size);
void RegisterPointer(const char* name, const void* ptr);
void UnregisterPointer(const void* ptr);
int PointerId(const void* ptr);
}  // namespace recordreplay

#endif  // RTC_BASE_RECORD_REPLAY_H_
