#pragma once
class SceneManager final
{
public: // ’è‹`
    enum Scene
    {
        Title,
        NewGame,
        GamePlay,
        GameClear
    };

public: // Ã“IŠÖ”
    static SceneManager* GetInstance(void);

public: // ŠÖ”
    void ChangeScene(int nextScene) { currentScene_ = nextScene; }
    void Draw(void);

public: // •Ï”
    int currentScene_{ 0 };

private: // singleton
    SceneManager(void) = default;
    ~SceneManager(void) = default;
    SceneManager(const SceneManager & ins) = delete;
    SceneManager& operator=(const SceneManager & ins) = delete;
};