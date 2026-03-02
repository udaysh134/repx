<!--
===========================================================================
GUIDELINES
===========================================================================

This file serves as an internal engineering journal for RepX.
It captures developer thinking, reasoning, and architectural evolution.

It is NOT :
- A replacement for git commit history
- A replacement for CHANGELOG.md
- A strict rule-based reporting system

It IS :
- A structured space to record why decisions were made
- A historical record of how the system evolved
- A communication layer between developers


===========================================================================
RULES (Important)
===========================================================================

1. Insert new entries at the top (latest first).
2. Use the date format : "Mar 02, 2026 - Monday".
3. One section per developer per day.
4. Developer name must link to GitHub profile:
    - [Full Name](https://github.com/username)
5. Use bullet points for main log entries.
6. Keep entries concise (one-liners or short summaries).
7. Avoid logging trivial or cosmetic changes.
8. When writing `Reason` and `Impact` :
   - Write them on consecutive lines.
   - Add TWO trailing spaces at the end of the `Reason` line.
   - Do NOT insert a blank line between them.
   - This ensures proper line break without visual spacing gap.

    Correct format:

    `Reason` : Explanation here.··
    `Impact` : Explanation here.

    (The two dots above represent two trailing spaces.)

--------------------------------------------------

1. Reason is mandatory.
    - Every entry must explain WHY the change was made.
    - Code changes are visible in git - thinking is not.
2. Impact is optional.
    - If the change has architectural or structural consequences,
    - mention expected or observed impact.
3. Write naturally.
    - This is human-readable engineering journaling.
    - Avoid robotic phrasing or over-formality.
4. Do not over-explain.
    - Keep logs short, but meaningful.


===========================================================================
TEMPLATE (Example)
===========================================================================

## 🗞️ Mar 02, 2026 - Monday
#### [Dev_1](https://github.com/dev_1)
- Separated layout computation from renderer responsibilities.
- Removed implicit dimension recalculations inside render layer.

- `Reason` : Renderer performing computation blurred module responsibility and weakened deterministic flow.
- `Impact` : Layout is now finalized before rendering begins, improving predictability and future scalability.

#### [Dev_2](https://github.com/dev_2)
- Introduced a centralized configuration struct inside core instead of passing scattered constants across modules.
- Removed hardcoded layout values from app layer.
- Decided not to introduce a third-party terminal abstraction library.
- Kept rendering dependent on native Windows console APIs.

- `Reason` : Configuration was implicitly spreading across multiple files, which risked silent inconsistency as the system grows.


===========================================================================
IMPORTANT NOTES
===========================================================================

- Dev Logs begin after the release of v0.1.0, prior development is not recorded here.
- If there is no meaningful reasoning, it likely does not belong in this file.
- This file is for architectural memory - not activity tracking.
- Never modify or remove this guidelines section.
-->