#include <windows.h>
#include <map>
#include <string>
#include <iostream>
#include <thread>

using namespace std;

// ���� ����
bool g_isInputChanged = false; // �Է°� ���� ���� ����
map<char, char> g_keyMapping; // ���� Ű�� ���� Ű ����
HHOOK g_keyboardHook; // ���� �� �ڵ�
bool g_isProcessingKey = false; // Ű ���� ������ ����
map<char, bool> g_keyPressed; // ���� Ű ����

// Ű���� ��ŷ �Լ�
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && !g_isProcessingKey) {
        KBDLLHOOKSTRUCT* pKbd = (KBDLLHOOKSTRUCT*)lParam;
        char key = (char)pKbd->vkCode; // ���� Ű �ڵ�κ��� ���� Ű �� ��������

        // Start ������ ���� Ű �Է��� ����
        if (g_isInputChanged && g_keyMapping.find(key) != g_keyMapping.end()) {
            // ���ε� Ű �̺�Ʈ�� ó�� ������ ǥ��
            g_isProcessingKey = true;

            // ���ε� Ű ó��
            char mappedKey = g_keyMapping[key];

            if (mappedKey == 'A') {
                if (wParam == WM_KEYDOWN) {
                    if (!g_keyPressed['A']) {
                        keybd_event(VK_CONTROL, 0, 0, 0); // Ctrl ������
                        Sleep(100);
                        keybd_event(mappedKey, 0, 0, 0); // A Ű ������
                        g_keyPressed['A'] = true; // A Ű�� ���ȴٰ� ǥ��
                    }
                } else if (wParam == WM_KEYUP) {
                    keybd_event(mappedKey, 0, KEYEVENTF_KEYUP, 0); // A Ű ����
                    Sleep(100);
                    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0); // Ctrl ����
                    g_keyPressed['A'] = false; // A Ű�� �������ٰ� ǥ��
                }
            } else {
                if (wParam == WM_KEYDOWN) {
                    if (!g_keyPressed['A']) {
                        keybd_event(mappedKey, 0, 0, 0); // ���ε� Ű ������
                        g_keyPressed['A'] = true; // A Ű�� ���ȴٰ� ǥ��
                        Sleep(100);
                    }
                } else if (wParam == WM_KEYUP) {
                    keybd_event(mappedKey, 0, KEYEVENTF_KEYUP, 0); // ���ε� Ű ����
                    g_keyPressed['A'] = false; // A Ű�� �������ٰ� ǥ��
                    Sleep(100);
                }
            }

            g_isProcessingKey = false;
            return 1; // �߰� ó���� ���� ���� Ű �̺�Ʈ�� ��ȯ
        }
    }
    return CallNextHookEx(g_keyboardHook, nCode, wParam, lParam); // �ļ� �̺�Ʈ ����
}

// Start ��ư Ŭ�� ó��
void OnStartButtonClick(HWND hwnd) {
    g_keyMapping = {
        {'Q', '1'},
        {'W', '2'},
        {'E', '3'},
        {'R', '4'},
        {'T', '5'},
        {'A', '6'},
        {'S', '7'},
        {'D', '8'},
        {'F', '9'},
        {'G', '0'},
        {'1', 'A'}
    };

    g_isInputChanged = true; // �Է°� ���� ���� ����s
}

// Stop ��ư Ŭ�� ó��
void OnStopButtonClick(HWND hwnd) {
    g_isInputChanged = false; // "Stop" ��ư Ŭ�� �� �Է� �� ���� ����
}

// ������ ���ν��� ����
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case 1: // Start ��ư Ŭ��
                    OnStartButtonClick(hwnd);
                    break;
                case 2: // Stop ��ư Ŭ��
                    OnStopButtonClick(hwnd);
                    break;
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0); // �޽��� ���� ����
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam); // �⺻ �޽��� ó��
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    // �� ��ġ
    g_keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (g_keyboardHook == NULL) {
        MessageBox(NULL, "Failed to install keyboard hook!", "Error", MB_OK);
        return 0;
    }

    const char CLASS_NAME[] = "MyWindowClass";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc; // ������ ���ν���
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    if (!RegisterClass(&wc)) {
        return 0;
    }

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "My GUI Application",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    // Start ��ư ����
    HWND hStartButton = CreateWindow(
        "BUTTON", "Start", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        100, 100, 100, 50, hwnd, (HMENU)1, hInstance, NULL
    );

    // Stop ��ư ����
    HWND hStopButton = CreateWindow(
        "BUTTON", "Stop", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        300, 100, 100, 50, hwnd, (HMENU)2, hInstance, NULL
    );

    // â ǥ��
    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    // �޽��� ����
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // �� ����
    UnhookWindowsHookEx(g_keyboardHook);

    return 0;
}
