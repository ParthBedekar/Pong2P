<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>SFML Pong</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
            line-height: 1.6;
            margin: 40px;
            background: #0f172a;
            color: #e5e7eb;
        }
        h1, h2, h3 {
            color: #38bdf8;
        }
        code, pre {
            background: #020617;
            padding: 6px 10px;
            border-radius: 6px;
            color: #a5f3fc;
        }
        pre {
            padding: 14px;
            overflow-x: auto;
        }
        ul {
            margin-left: 20px;
        }
        .container {
            max-width: 900px;
            margin: auto;
        }
        footer {
            margin-top: 40px;
            font-size: 0.9rem;
            color: #94a3b8;
        }
    </style>
</head>
<body>
<div class="container">

<h1>🏓 SFML Pong (Two-Player)</h1>

<p>
A simple <strong>two-player Pong game</strong> built using
<strong>SFML (Simple and Fast Multimedia Library)</strong> to understand
real-time game loops, collision detection, and modular C++ design.
</p>

<h2>🎮 Gameplay</h2>
<ul>
    <li><strong>Top paddle:</strong> A / D</li>
    <li><strong>Bottom paddle:</strong> ← / →</li>
    <li>Ball bounces off walls and paddles</li>
    <li>Ball touching the top or bottom wall ends the game</li>
    <li>Game pauses automatically after a win</li>
</ul>

<h2>🧱 Project Structure</h2>
<pre>
src/
 ├── main.cpp        // Game loop & state handling
 ├── Paddle.hpp/.cpp // Paddle logic & input handling
 ├── Ball.hpp/.cpp   // Ball physics & collision logic
</pre>

<p>
The project follows a <strong>modular design</strong>:
each game object manages its own update and rendering logic.
</p>

<h2>🧠 Key Concepts Used</h2>
<ul>
    <li>Game loop (update → draw)</li>
    <li>Delta time using <code>sf::Clock</code></li>
    <li>Frame-independent movement</li>
    <li>Bounding box collision (<code>getGlobalBounds()</code>)</li>
    <li>Keyboard input handling</li>
    <li>Pause state management</li>
    <li>Object-oriented programming with SFML</li>
</ul>

<h2>🛠 Requirements</h2>
<ul>
    <li>C++ compiler</li>
    <li>SFML (Graphics module)</li>
</ul>

<h2>📌 Notes</h2>
<ul>
    <li>SFML is a <strong>multimedia library</strong>, not a game engine</li>
    <li>This project focuses on <strong>core game programming fundamentals</strong></li>
</ul>

<h2>🚀 Possible Improvements</h2>
<ul>
    <li>Score system</li>
    <li>Ball angle variation based on paddle hit</li>
    <li>Restart / reset functionality</li>
    <li>AI-controlled paddle</li>
</ul>

<footer>
    <p>Built as a learning project using SFML and C++.</p>
</footer>

</div>
</body>
</html>
