#pragma once
class SceneManager
{
public: // 定義
    enum Scene
    {
        Title,
        NewGame,
        GamePlay,
        GameClear
    };

public: // 静的関数
    static SceneManager* GetInstance(void);

public: // 関数
    void ChangeScene(int nextScene) { currentScene_ = nextScene; }
    void Draw(void);

public: // 変数
    int currentScene_{ 0 };

private: // singleton
    SceneManager(void) = default;
    ~SceneManager(void) = default;
    SceneManager(const SceneManager & ins) = delete;
    SceneManager& operator=(const SceneManager & ins) = delete;
};