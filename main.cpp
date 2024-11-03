#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

#define TH32CS_PROCESS 0x00000002

DWORD GetProcessID(const wchar_t* processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_PROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return 0;
    }

    PROCESSENTRY32W processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32W);

    if (Process32FirstW(hSnapshot, &processEntry)) {
        do {
            if (wcscmp(processEntry.szExeFile, processName) == 0) {
                CloseHandle(hSnapshot);
                return processEntry.th32ProcessID; // Retornamos el PID
            }
        } while (Process32NextW(hSnapshot, &processEntry));
    }

    CloseHandle(hSnapshot);
    return 0; // Si no se encontró el proceso, retornamos 0
}

int main() {
    const wchar_t* processName = L"cs2.exe"; // Nota la 'L' antes del string
    DWORD processId = GetProcessID(processName);

    if (!processId != 0) {
        std::wcout << L"Process not found." << std::endl;
        return 1;
    }
    //Obtener las variables de memoria del juego

    //Sobreescribir las variables del juego
    return 0;
}
