#pragma once
class SceneManager final
{
public: // ��`
    enum Scene
    {
        Title,
        NewGame,
        GamePlay,
        GameClear
    };

public: // �ÓI�֐�
    static SceneManager* GetInstance(void);

public: // �֐�
    void ChangeScene(int nextScene) { currentScene_ = nextScene; }
    void Draw(void);

public: // �ϐ�
    int currentScene_{ 0 };

private: // singleton
    SceneManager(void) = default;
    ~SceneManager(void) = default;
    SceneManager(const SceneManager & ins) = delete;
    SceneManager& operator=(const SceneManager & ins) = delete;
};