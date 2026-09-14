Please review and port the relevant Turtle full-activity performance fixes into our shared ManTech playerbots used by CMaNGOS Classic, TBC, and WotLK.

Read the completed report first:
`D:\WoW Emu\ManTech\ManTech Turtle\docs\TURTLE_FULL_ACTIVITY_FIXES_2026-09-14.md`

Authoritative Turtle source:
`D:\WoW Emu\ManTech\ManTech Turtle`

Our inspected CMaNGOS Arch4 reference tree was:
`C:\Users\root\Documents\Codex\2026-09-06\i-ne\work\arch4\src`
Confirm the current authoritative trees in your task before editing.

Start with the concrete behavior bug in `strategy/actions/SayAction.cpp`, `ChatReplyAction::ChatReplyDo`. In the eligible LLM branch, `!chanName.empty() && !ai->ChannelHasRealPlayer(chanName)` used to set `player = nullptr`. This skipped the LLM branch's terminal return and fell through to canned `SendGeneralResponse`, allowing bot reply chains after humans left even with LLM bot-to-bot chance zero. Turtle now returns explicitly for this no-audience branch. The inspected CMaNGOS shared module contains the same old code. Verify and fix it there. Preserve early LFG/WTB/special handlers, non-LLM/blocked channels, direct messages, and human-present policy. Do not globally mute chat to hide the issue. Adapt `run_chat_audience_test.py` (2,304 source-derived dispatch cases); it mocks model/network calls and does not validate model quality.

The other relevant shared-module candidates are:

1. In PlayerbotAI::HandleBotOutgoingPacket, perform free-bot response selection before expensive strategy, locked cooldown-value, and sender-name lookups. Preserve the human LLM cooldown exception, recording, addon/debug filtering, mentions, master/BG/guild rules, special links, and response probabilities. RNG ordering for discarded messages is not guaranteed identical.
2. In ChatHelper, avoid item/quest parsing when their token is absent and reuse immutable compiled regexes. Preserve duplicate, malformed, and overflow behavior.
3. ChatPrefix.h removes repeated MSVC global locale/facet locking from the toxic-link prefix check. Verify the receiving cores do not change the C++ global locale at runtime. Preserve the actual Boost comparison semantics rather than substituting an ASCII-only comparison. Windows and Linux performance results may differ.
4. ChatBroadcastSender.h and the synchronous channel send sites reuse the same sender classification during a broadcast. Preserve native random-account/free-alt/real-player semantics, nested calls, exception cleanup, and per-thread isolation. Do not carry this scope into asynchronous queues or retain player pointers. Calls outside the matching synchronous scope must retain their native fallback lookup.

Inspect the actual current code before applying anything; some changes may already have landed independently. Reuse our native facilities and preserve owner-thread/lifetime contracts. Implement the useful changes in the shared module rather than making three divergent copies.

Do not blindly port these Turtle-specific changes:

- Turtle Channel::SendToAll removed allocated PlayerWrapper/shared_ptr adapters. The inspected Classic delivery already uses Player pointers directly; verify TBC/WotLK rather than transplanting Turtle's node/master machinery.
- Turtle's session packet-activity flag initialization applies only if the receiving core has the equivalent uninitialized state.
- Turtle's background cadence was informed by CMaNGOS. In particular, the timer-advancement/UpdateAI argument contract differs; do not copy it back and advance timers twice.
- Do not transplant Turtle's world-action queue or change ownership to make tests pass.

Use the focused Turtle tests as evidence and adapt them to actual CMaNGOS code/contracts: run_chat_admission_test.py (46,080 policy cases), run_chat_link_test.py, ChatPrefixTest.cpp, and ChatBroadcastSenderTest.cpp. Verify classic/TBC/WotLK chat packet variants and compile all three development cores. Compare measured chat cost and world ticks under an unchanged configuration before claiming a benefit. Keep the existing production activity percentages and production servers unchanged.

Complete the relevant implementation and normal development validation without repeated checkpoints. Provide a concise report of what changed, what already existed, what was deliberately not ported, build/test results for all three cores, and any behavior or concurrency limits. Do not claim that Turtle's 100% activity result proves the same capacity for CMaNGOS without its own measured test.

Turtle result for context: build 82 held 10,000 online/eligible bots with zero human players for the bounded acceptance interval, sampled average ticks 83–104 ms, followed by successful native invite/summon/loot/logout checks. This supports the fix in this environment; measure each receiving CMaNGOS environment independently.
