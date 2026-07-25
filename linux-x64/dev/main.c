/*
 * Copyright (C) 2026 ProjectNative
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 only,
 * as published by the Free Software Foundation.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#include <io.h>
#define PATH_SEP '\\'
#define PATH_SEP_STR "\\"
#define STRICMP _stricmp
#define STRDUP _strdup
#else
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <strings.h>
#define PATH_SEP '/'
#define PATH_SEP_STR "/"
#define STRICMP strcasecmp
#define STRDUP strdup
#endif

unsigned char HEADER_WINX64_STABLE[] = {
0x00, 0x50, 0x4E, 0x2E, 0x2E, 0x2E, 0x41, 0x54,
    0x54, 0x52, 0x41, 0x58, 0x33, 0x30, 0x31, 0x2E,
    0x46, 0x55, 0x43, 0x4B, 0x45, 0x44, 0x5A, 0x49,
    0x4E, 0x39, 0x30, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB,
    0xFA, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3,
    0xF2, 0xF1, 0xF0, 0xEF, 0xEE, 0xED, 0xEC, 0xEB,
    0xEA, 0xE9, 0xE8, 0xE7, 0xE6, 0xE5, 0xE4, 0xE3,
    0xE2, 0xE1, 0xE0, 0xDF, 0xDE, 0xDD, 0xDC, 0xDB,
    0xDA, 0xD9, 0xD8, 0xD7, 0xD6, 0xD5, 0xD4, 0xD3,
    0xD2, 0xD1, 0xD0, 0xCF, 0xCE, 0xCD, 0xCC, 0xCB,
    0xCA, 0xC9, 0xC8, 0xC7, 0xC6, 0xC5, 0xC4,

    0x76, 0x32, 0x40, 0x68, 0x74, 0x74, 0x70, 0x73,
    0x3A, 0x2F, 0x2F, 0x64, 0x6F, 0x77, 0x6E, 0x6C,
    0x6F, 0x61, 0x64, 0x2E, 0x70, 0x72, 0x6F, 0x6A,
    0x65, 0x63, 0x74, 0x6E, 0x61, 0x74, 0x69, 0x76,
    0x65, 0x2E, 0x78, 0x79, 0x7A, 0x2F, 0x73, 0x74,
    0x61, 0x62, 0x6C, 0x65, 0x2F, 0x67, 0x65, 0x74,
    0x6C, 0x6F, 0x73, 0x74, 0x7A, 0x2F, 0x77, 0x69,
    0x6E, 0x2D, 0x78, 0x36, 0x34, 0x2F,

    0x88, 0x87, 0x86, 0x85, 0x84, 0x83, 0x82, 0x81,
    0x80, 0x7F, 0x7E, 0x7D, 0x7C, 0x7B, 0x7A, 0x79,
    0x78, 0x77, 0x76, 0x75, 0x74, 0x73, 0x72, 0x71,
    0x70, 0x6F, 0x6E, 0x6D, 0x6C, 0x6B, 0x6A, 0x69,
    0x68, 0x67, 0x66, 0x65, 0x64, 0x63, 0x62, 0x61,
    0x60, 0x5F, 0x5E, 0x5D, 0x5C, 0x5B, 0x5A, 0x59,
    0x58, 0x57, 0x56, 0x55, 0x54, 0x53, 0x52, 0x51,
    0x50, 0x4F, 0x4E, 0x4D, 0x4C, 0x4B, 0x4A, 0x49,
    0x48, 0x47, 0x46, 0x45, 0x44, 0x43, 0x42, 0x41,
    0x40, 0x3F, 0x3E, 0x3D, 0x3C, 0x3B, 0x3A, 0x39,
    0x38, 0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31,
    0x30, 0x2F, 0x2E, 0x2D, 0x2C, 0x2B, 0x2A, 0x29,
    0x28, 0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21,
    0x20, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19,
    0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11,
    0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09,
    0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01,
    0xFF, 0xFE, 0xD3, 0xD9, 0xD1, 0xF3, 0xF0, 0xF1,
    0xF9, 0xE5, 0xEA, 0xA1, 0x12, 0x19, 0x83, 0xDA,
    0xD2, 0x2F, 0x2E
};

unsigned char HEADER_WINX64_DEV[] = {
    0x00, 0x50, 0x4E, 0x2E, 0x2E, 0x2E, 0x41, 0x54,
    0x54, 0x52, 0x41, 0x58, 0x33, 0x30, 0x31, 0x2E,
    0x46, 0x55, 0x43, 0x4B, 0x45, 0x44, 0x5A, 0x49,
    0x4E, 0x39, 0x30, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB,
    0xFA, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3,
    0xF2, 0xF1, 0xF0, 0xEF, 0xEE, 0xED, 0xEC, 0xEB,
    0xEA, 0xE9, 0xE8, 0xE7, 0xE6, 0xE5, 0xE4, 0xE3,
    0xE2, 0xE1, 0xE0, 0xDF, 0xDE, 0xDD, 0xDC, 0xDB,
    0xDA, 0xD9, 0xD8, 0xD7, 0xD6, 0xD5, 0xD4, 0xD3,
    0xD2, 0xD1, 0xD0, 0xCF, 0xCE, 0xCD, 0xCC, 0xCB,
    0xCA, 0xC9, 0xC8, 0xC7, 0xC6, 0xC5, 0xC4,

    0x76, 0x32, 0x40, 0x68, 0x74, 0x74, 0x70, 0x73,
    0x3A, 0x2F, 0x2F, 0x64, 0x6F, 0x77, 0x6E, 0x6C,
    0x6F, 0x61, 0x64, 0x2E, 0x70, 0x72, 0x6F, 0x6A,
    0x65, 0x63, 0x74, 0x6E, 0x61, 0x74, 0x69, 0x76,
    0x65, 0x2E, 0x78, 0x79, 0x7A, 0x2F, 0x64, 0x65,
    0x76, 0x2F, 0x67, 0x65, 0x74, 0x6C, 0x6F, 0x73,
    0x74, 0x7A, 0x2F, 0x77, 0x69, 0x6E, 0x2D, 0x78,
    0x36, 0x34, 0x2F,

    0x88, 0x87, 0x86, 0x85, 0x84, 0x83, 0x82, 0x81,
    0x80, 0x7F, 0x7E, 0x7D, 0x7C, 0x7B, 0x7A, 0x79,
    0x78, 0x77, 0x76, 0x75, 0x74, 0x73, 0x72, 0x71,
    0x70, 0x6F, 0x6E, 0x6D, 0x6C, 0x6B, 0x6A, 0x69,
    0x68, 0x67, 0x66, 0x65, 0x64, 0x63, 0x62, 0x61,
    0x60, 0x5F, 0x5E, 0x5D, 0x5C, 0x5B, 0x5A, 0x59,
    0x58, 0x57, 0x56, 0x55, 0x54, 0x53, 0x52, 0x51,
    0x50, 0x4F, 0x4E, 0x4D, 0x4C, 0x4B, 0x4A, 0x49,
    0x48, 0x47, 0x46, 0x45, 0x44, 0x43, 0x42, 0x41,
    0x40, 0x3F, 0x3E, 0x3D, 0x3C, 0x3B, 0x3A, 0x39,
    0x38, 0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31,
    0x30, 0x2F, 0x2E, 0x2D, 0x2C, 0x2B, 0x2A, 0x29,
    0x28, 0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21,
    0x20, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19,
    0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11,
    0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09,
    0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01,
    0xFF, 0xFE, 0xD3, 0xD9, 0xD1, 0xF3, 0xF0, 0xF1,
    0xF9, 0xE5, 0xEA, 0xA1, 0x12, 0x19, 0x83, 0xDA,
    0xD2, 0x2F, 0x2E
};

unsigned char HEADER_LINUXX64_STABLE[] = {
    0x00, 0x50, 0x4E, 0x2E, 0x2E, 0x2E, 0x41, 0x54,
    0x54, 0x52, 0x41, 0x58, 0x33, 0x30, 0x31, 0x2E,
    0x46, 0x55, 0x43, 0x4B, 0x45, 0x44, 0x5A, 0x49,
    0x4E, 0x39, 0x30, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB,
    0xFA, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3,
    0xF2, 0xF1, 0xF0, 0xEF, 0xEE, 0xED, 0xEC, 0xEB,
    0xEA, 0xE9, 0xE8, 0xE7, 0xE6, 0xE5, 0xE4, 0xE3,
    0xE2, 0xE1, 0xE0, 0xDF, 0xDE, 0xDD, 0xDC, 0xDB,
    0xDA, 0xD9, 0xD8, 0xD7, 0xD6, 0xD5, 0xD4, 0xD3,
    0xD2, 0xD1, 0xD0, 0xCF, 0xCE, 0xCD, 0xCC, 0xCB,
    0xCA, 0xC9, 0xC8, 0xC7, 0xC6, 0xC5, 0xC4,

    0x76, 0x32, 0x40, 0x68, 0x74, 0x74, 0x70, 0x73,
    0x3A, 0x2F, 0x2F, 0x64, 0x6F, 0x77, 0x6E, 0x6C,
    0x6F, 0x61, 0x64, 0x2E, 0x70, 0x72, 0x6F, 0x6A,
    0x65, 0x63, 0x74, 0x6E, 0x61, 0x74, 0x69, 0x76,
    0x65, 0x2E, 0x78, 0x79, 0x7A, 0x2F, 0x73, 0x74,
    0x61, 0x62, 0x6C, 0x65, 0x2F, 0x67, 0x65, 0x74,
    0x6C, 0x6F, 0x73, 0x74, 0x7A, 0x2F, 0x6C, 0x69,
    0x6E, 0x75, 0x78, 0x2D, 0x78, 0x36, 0x34,

    0x88, 0x87, 0x86, 0x85, 0x84, 0x83, 0x82, 0x81,
    0x80, 0x7F, 0x7E, 0x7D, 0x7C, 0x7B, 0x7A, 0x79,
    0x78, 0x77, 0x76, 0x75, 0x74, 0x73, 0x72, 0x71,
    0x70, 0x6F, 0x6E, 0x6D, 0x6C, 0x6B, 0x6A, 0x69,
    0x68, 0x67, 0x66, 0x65, 0x64, 0x63, 0x62, 0x61,
    0x60, 0x5F, 0x5E, 0x5D, 0x5C, 0x5B, 0x5A, 0x59,
    0x58, 0x57, 0x56, 0x55, 0x54, 0x53, 0x52, 0x51,
    0x50, 0x4F, 0x4E, 0x4D, 0x4C, 0x4B, 0x4A, 0x49,
    0x48, 0x47, 0x46, 0x45, 0x44, 0x43, 0x42, 0x41,
    0x40, 0x3F, 0x3E, 0x3D, 0x3C, 0x3B, 0x3A, 0x39,
    0x38, 0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31,
    0x30, 0x2F, 0x2E, 0x2D, 0x2C, 0x2B, 0x2A, 0x29,
    0x28, 0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21,
    0x20, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19,
    0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11,
    0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09,
    0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01,
    0xFF, 0xFE, 0xD3, 0xD9, 0xD1, 0xF3, 0xF0, 0xF1,
    0xF9, 0xE5, 0xEA, 0xA1, 0x12, 0x19, 0x83, 0xDA,
    0xD2, 0x2F, 0x2E
};

unsigned char HEADER_LINUXX64_DEV[] = {
    0x00, 0x50, 0x4E, 0x2E, 0x2E, 0x2E, 0x41, 0x54,
    0x54, 0x52, 0x41, 0x58, 0x33, 0x30, 0x31, 0x2E,
    0x46, 0x55, 0x43, 0x4B, 0x45, 0x44, 0x5A, 0x49,
    0x4E, 0x39, 0x30, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB,
    0xFA, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3,
    0xF2, 0xF1, 0xF0, 0xEF, 0xEE, 0xED, 0xEC, 0xEB,
    0xEA, 0xE9, 0xE8, 0xE7, 0xE6, 0xE5, 0xE4, 0xE3,
    0xE2, 0xE1, 0xE0, 0xDF, 0xDE, 0xDD, 0xDC, 0xDB,
    0xDA, 0xD9, 0xD8, 0xD7, 0xD6, 0xD5, 0xD4, 0xD3,
    0xD2, 0xD1, 0xD0, 0xCF, 0xCE, 0xCD, 0xCC, 0xCB,
    0xCA, 0xC9, 0xC8, 0xC7, 0xC6, 0xC5, 0xC4,

    0x76, 0x32, 0x40, 0x68, 0x74, 0x74, 0x70, 0x73,
    0x3A, 0x2F, 0x2F, 0x64, 0x6F, 0x77, 0x6E, 0x6C,
    0x6F, 0x61, 0x64, 0x2E, 0x70, 0x72, 0x6F, 0x6A,
    0x65, 0x63, 0x74, 0x6E, 0x61, 0x74, 0x69, 0x76,
    0x65, 0x2E, 0x78, 0x79, 0x7A, 0x2F, 0x64, 0x65,
    0x76, 0x2F, 0x67, 0x65, 0x74, 0x6C, 0x6F, 0x73,
    0x74, 0x7A, 0x2F, 0x6C, 0x69, 0x6E, 0x75, 0x78,
    0x2D, 0x78, 0x36, 0x34,

    0x88, 0x87, 0x86, 0x85, 0x84, 0x83, 0x82, 0x81,
    0x80, 0x7F, 0x7E, 0x7D, 0x7C, 0x7B, 0x7A, 0x79,
    0x78, 0x77, 0x76, 0x75, 0x74, 0x73, 0x72, 0x71,
    0x70, 0x6F, 0x6E, 0x6D, 0x6C, 0x6B, 0x6A, 0x69,
    0x68, 0x67, 0x66, 0x65, 0x64, 0x63, 0x62, 0x61,
    0x60, 0x5F, 0x5E, 0x5D, 0x5C, 0x5B, 0x5A, 0x59,
    0x58, 0x57, 0x56, 0x55, 0x54, 0x53, 0x52, 0x51,
    0x50, 0x4F, 0x4E, 0x4D, 0x4C, 0x4B, 0x4A, 0x49,
    0x48, 0x47, 0x46, 0x45, 0x44, 0x43, 0x42, 0x41,
    0x40, 0x3F, 0x3E, 0x3D, 0x3C, 0x3B, 0x3A, 0x39,
    0x38, 0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31,
    0x30, 0x2F, 0x2E, 0x2D, 0x2C, 0x2B, 0x2A, 0x29,
    0x28, 0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21,
    0x20, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19,
    0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11,
    0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09,
    0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01,
    0xFF, 0xFE, 0xD3, 0xD9, 0xD1, 0xF3, 0xF0, 0xF1,
    0xF9, 0xE5, 0xEA, 0xA1, 0x12, 0x19, 0x83, 0xDA,
    0xD2, 0x2F, 0x2E
};

unsigned char* DEFAULT_HEADER = HEADER_LINUXX64_DEV;
const size_t DEFAULT_HEADER_SIZE = sizeof(HEADER_LINUXX64_DEV);

typedef struct {
    char* path;
    unsigned char* data;
    size_t size;
} FileEntry;

typedef struct {
    FileEntry* entries;
    size_t count;
    size_t capacity;
} FileList;

void filelist_init(FileList* list) {
    list->entries = NULL;
    list->count = 0;
    list->capacity = 0;
}

int filelist_add(FileList* list, const char* path, unsigned char* data, size_t size) {
    if (list->count >= list->capacity) {
        size_t new_capacity = list->capacity ? list->capacity * 2 : 16;
        FileEntry* new_entries = (FileEntry*)realloc(list->entries, new_capacity * sizeof(FileEntry));
        if (!new_entries) {
            fprintf(stderr, "[-] Memory allocation failed\n");
            return 0;
        }
        list->entries = new_entries;
        list->capacity = new_capacity;
    }

    list->entries[list->count].path = STRDUP(path);
    list->entries[list->count].data = data;
    list->entries[list->count].size = size;

    if (!list->entries[list->count].path) {
        fprintf(stderr, "[-] Memory allocation failed for path\n");
        return 0;
    }

    list->count++;
    return 1;
}

void filelist_free(FileList* list) {
    if (list->entries) {
        for (size_t i = 0; i < list->count; i++) {
            if (list->entries[i].path) {
                free(list->entries[i].path);
                list->entries[i].path = NULL;
            }
            if (list->entries[i].data) {
                free(list->entries[i].data);
                list->entries[i].data = NULL;
            }
        }
        free(list->entries);
        list->entries = NULL;
    }
    list->count = 0;
    list->capacity = 0;
}


int is_valid_archive_extension(const char* filename) {
    const char* ext = strrchr(filename, '.');
    if (!ext) return 0;

    if (STRICMP(ext, ".GETLOST") == 0) return 1;
    if (STRICMP(ext, ".GETLOSTZ") == 0) return 1;

    size_t len = strlen(filename);
    if (len >= 10) {
        const char* last_10 = filename + len - 10;
        if (STRICMP(last_10, ".GETLOST.Z") == 0) return 1;
    }
    return 0;
}


unsigned char* encode_content(const unsigned char* data, size_t size, size_t* out_size) {
    size_t max_encoded = size * 7 + 1;
    unsigned char* encoded = (unsigned char*)malloc(max_encoded);
    if (!encoded) {
        fprintf(stderr, "[-] Memory allocation failed\n");
        *out_size = 0;
        return NULL;
    }

    size_t pos = 0;

    for (size_t i = 0; i < size; i++) {
        unsigned char byte = data[i];

        if (pos + 8 > max_encoded) {
            max_encoded *= 2;
            unsigned char* new_encoded = (unsigned char*)realloc(encoded, max_encoded);
            if (!new_encoded) {
                fprintf(stderr, "[-] Memory allocation failed during encoding\n");
                free(encoded);
                *out_size = 0;
                return NULL;
            }
            encoded = new_encoded;
        }

        if (byte == 0x20) {
            encoded[pos++] = '\\';
            encoded[pos++] = 's';
        }
        else if (byte == 0x09) {
            encoded[pos++] = '\\';
            encoded[pos++] = 't';
        }
        else if (byte == 0x0A) {
            encoded[pos++] = '\\';
            encoded[pos++] = 'n';
        }
        else if (byte == 0x0D) {
            encoded[pos++] = '\\';
            encoded[pos++] = 'r';
        }
        else if (byte == 0x5C) {
            encoded[pos++] = '\\';
            encoded[pos++] = '\\';
        }
        else {
            int written = snprintf((char*)(encoded + pos), max_encoded - pos, "\\c0x%02X", byte);
            if (written > 0) pos += written;
        }
    }
    encoded[pos] = 0;
    *out_size = pos;
    return encoded;
}

unsigned char* decode_content(const unsigned char* encoded, size_t size, size_t* out_size) {
    if (!encoded || size == 0) {
        *out_size = 0;
        return NULL;
    }

    unsigned char* decoded = (unsigned char*)malloc(size);
    if (!decoded) {
        fprintf(stderr, "[-] Memory allocation failed\n");
        *out_size = 0;
        return NULL;
    }

    size_t pos = 0;
    size_t i = 0;

    while (i < size) {
        if (encoded[i] == '\\' && i + 1 < size) {
            char next = encoded[i + 1];
            if (next == 's') {
                if (pos < size) decoded[pos++] = 0x20;
                i += 2;
            }
            else if (next == 't') {
                if (pos < size) decoded[pos++] = 0x09;
                i += 2;
            }
            else if (next == 'n') {
                if (pos < size) decoded[pos++] = 0x0A;
                i += 2;
            }
            else if (next == 'r') {
                if (pos < size) decoded[pos++] = 0x0D;
                i += 2;
            }
            else if (next == '\\') {
                if (pos < size) decoded[pos++] = 0x5C;
                i += 2;
            }
            else if (next == 'c' && i + 5 < size &&
                encoded[i + 2] == '0' && encoded[i + 3] == 'x') {
                char hex[3] = { encoded[i + 4], encoded[i + 5], 0 };
                if (pos < size) decoded[pos++] = (unsigned char)strtol(hex, NULL, 16);
                i += 6;
            }
            else {
                if (pos < size) decoded[pos++] = encoded[i];
                i += 1;
            }
        }
        else {
            if (pos < size) decoded[pos++] = encoded[i];
            i += 1;
        }
    }

    *out_size = pos;
    return decoded;
}

void mkdir_recursive(const char* dir) {
    char tmp[1024];
    char* p = NULL;
    size_t len;

    strncpy(tmp, dir, sizeof(tmp) - 1);
    tmp[sizeof(tmp) - 1] = 0;
    len = strlen(tmp);

    if (len > 0 && (tmp[len - 1] == '/' || tmp[len - 1] == '\\'))
        tmp[len - 1] = 0;

    for (p = tmp + 1; *p; p++) {
        if (*p == '/' || *p == '\\') {
            *p = 0;
#ifdef _WIN32
            _mkdir(tmp);
#else
            mkdir(tmp, 0755);
#endif
            *p = PATH_SEP;
        }
    }
#ifdef _WIN32
    _mkdir(tmp);
#else
    mkdir(tmp, 0755);
#endif
}

#ifdef _WIN32
void walk_directory(const char* dir, const char* base_dir, FileList* list) {
    WIN32_FIND_DATAA findData;
    char searchPath[1024];
    snprintf(searchPath, sizeof(searchPath), "%s\\*", dir);

    HANDLE hFind = FindFirstFileA(searchPath, &findData);
    if (hFind == INVALID_HANDLE_VALUE) return;

    do {
        if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0)
            continue;

        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s\\%s", dir, findData.cFileName);

        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            walk_directory(fullPath, base_dir, list);
        }
        else {
            FILE* f = NULL;
            if (fopen_s(&f, fullPath, "rb") != 0 || !f) continue;

            fseek(f, 0, SEEK_END);
            size_t size = ftell(f);
            fseek(f, 0, SEEK_SET);

            unsigned char* data = (unsigned char*)malloc(size);
            if (!data) {
                fclose(f);
                continue;
            }

            if (fread(data, 1, size, f) != size) {
                free(data);
                fclose(f);
                continue;
            }
            fclose(f);

            char relPath[1024];
            size_t baseLen = strlen(base_dir);
            if (fullPath[baseLen] == '\\') baseLen++;
            strncpy(relPath, fullPath + baseLen, sizeof(relPath) - 1);
            relPath[sizeof(relPath) - 1] = 0;

            for (char* p = relPath; *p; p++) {
                if (*p == '\\') *p = '/';
            }

            filelist_add(list, relPath, data, size);
        }
    } while (FindNextFileA(hFind, &findData));

    FindClose(hFind);
}
#else
void walk_directory(const char* dir, const char* base_dir, FileList* list) {
    DIR* d = opendir(dir);
    if (!d) return;

    struct dirent* entry;
    char fullPath[1024];
    struct stat st;

    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullPath, sizeof(fullPath), "%s/%s", dir, entry->d_name);
        if (stat(fullPath, &st) == -1) continue;

        if (S_ISDIR(st.st_mode)) {
            walk_directory(fullPath, base_dir, list);
        }
        else {
            FILE* f = fopen(fullPath, "rb");
            if (!f) continue;

            fseek(f, 0, SEEK_END);
            size_t size = ftell(f);
            fseek(f, 0, SEEK_SET);

            unsigned char* data = (unsigned char*)malloc(size);
            if (!data) {
                fclose(f);
                continue;
            }

            if (fread(data, 1, size, f) != size) {
                free(data);
                fclose(f);
                continue;
            }
            fclose(f);

            char base_copy[1024];
            strncpy(base_copy, base_dir, sizeof(base_copy) - 1);
            base_copy[sizeof(base_copy) - 1] = 0;
            size_t base_len = strlen(base_copy);
            while (base_len > 0 && (base_copy[base_len - 1] == '/' ||
                                    base_copy[base_len - 1] == '\\'))
                base_copy[--base_len] = 0;

            const char* rel = fullPath + base_len;
            if (*rel == '/') rel++;

            char relPath[1024];
            strncpy(relPath, rel, sizeof(relPath) - 1);
            relPath[sizeof(relPath) - 1] = 0;

            for (char* p = relPath; *p; p++) {
                if (*p == '\\') *p = '/';
            }

            filelist_add(list, relPath, data, size);
        }
    }
    closedir(d);
}
#endif

FileList* parse_archive(const char* filename) {
    if (!is_valid_archive_extension(filename)) {
        fprintf(stderr, "[-] Invalid archive extension. Must be .GETLOST, .GETLOSTZ, or .GETLOST.Z\n");
        return NULL;
    }

    FileList* list = (FileList*)malloc(sizeof(FileList));
    if (!list) {
        fprintf(stderr, "[-] Memory allocation failed\n");
        return NULL;
    }
    filelist_init(list);

    FILE* f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "[-] File not found: %s\n", filename);
        free(list);
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    size_t file_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (file_size <= DEFAULT_HEADER_SIZE) {
        fprintf(stderr, "[-] File too small\n");
        fclose(f);
        free(list);
        return NULL;
    }

    unsigned char* data = (unsigned char*)malloc(file_size + 1);
    if (!data) {
        fprintf(stderr, "[-] Memory allocation failed\n");
        fclose(f);
        free(list);
        return NULL;
    }

    size_t bytes_read = fread(data, 1, file_size, f);
    fclose(f);

    if (bytes_read != file_size) {
        fprintf(stderr, "[-] Failed to read file\n");
        free(data);
        return list;
    }
    data[file_size] = 0;

    size_t pos = DEFAULT_HEADER_SIZE;

    while (pos < file_size) {
        while (pos < file_size && data[pos] == 0) pos++;
        if (pos >= file_size) break;

        size_t entry_start = pos;
        size_t entry_end = pos;
        while (entry_end < file_size && data[entry_end] != 0) entry_end++;

        size_t entry_len = entry_end - entry_start;
        if (entry_len == 0) {
            pos = entry_end + 1;
            continue;
        }

        char* entry_str = (char*)malloc(entry_len + 1);
        if (!entry_str) {
            pos = entry_end + 1;
            continue;
        }
        memcpy(entry_str, data + entry_start, entry_len);
        entry_str[entry_len] = 0;

        char* eq_slash = strstr(entry_str, "=/");
        if (!eq_slash) {
            free(entry_str);
            pos = entry_end + 1;
            continue;
        }

        char* content_marker = strstr(eq_slash, ",content=");
        if (!content_marker) {
            free(entry_str);
            pos = entry_end + 1;
            continue;
        }

        size_t path_start = (eq_slash - entry_str) + 2;
        size_t path_len = content_marker - (entry_str + path_start);

        char* path = (char*)malloc(path_len + 1);
        if (!path) {
            free(entry_str);
            pos = entry_end + 1;
            continue;
        }
        memcpy(path, entry_str + path_start, path_len);
        path[path_len] = 0;

        size_t content_start = (content_marker - entry_str) + 9;
        size_t content_len = entry_len - content_start;

        size_t decoded_size = 0;
        unsigned char* decoded = decode_content(
            (unsigned char*)entry_str + content_start,
            content_len,
            &decoded_size
        );

        if (decoded) {
            filelist_add(list, path, decoded, decoded_size);
        }

        free(path);
        free(entry_str);

        pos = entry_end + 1;
    }

    free(data);
    return list;
}

void create_getlost(const char* input_dir, const char* output_path) {
    FileList list;
    filelist_init(&list);

    printf("[+] Walking directory: %s\n", input_dir);
    walk_directory(input_dir, input_dir, &list);

    if (list.count == 0) {
        fprintf(stderr, "[-] No files found\n");
        filelist_free(&list);
        return;
    }

    printf("[+] Found %zu files to pack\n", list.count);

    FILE* out = fopen(output_path, "wb");
    if (!out) {
        fprintf(stderr, "[-] Cannot create output file: %s\n", output_path);
        filelist_free(&list);
        return;
    }

    fwrite(DEFAULT_HEADER, 1, DEFAULT_HEADER_SIZE, out);

    size_t total_original = 0;
    size_t total_encoded = 0;

    for (size_t i = 0; i < list.count; i++) {
        size_t encoded_size;
        unsigned char* encoded = encode_content(list.entries[i].data, list.entries[i].size, &encoded_size);

        if (!encoded) {
            fprintf(stderr, "[-] Failed to encode: %s\n", list.entries[i].path);
            continue;
        }

        total_original += list.entries[i].size;
        total_encoded += encoded_size;

        fprintf(out, "file#%zu=/%s,content=", i + 1, list.entries[i].path);
        fwrite(encoded, 1, encoded_size, out);

        if (i < list.count - 1) {
            fputc(0, out);
        }

        printf("    [%zu] %s (%zu bytes -> %zu bytes)\n", i + 1, list.entries[i].path, list.entries[i].size, encoded_size);

        free(encoded);
    }

    fclose(out);

    printf("\n[+] Packed %zu files into %s\n", list.count, output_path);
    printf("    Original total: %zu bytes\n", total_original);
    printf("    Encoded total:  %zu bytes\n", total_encoded);

    filelist_free(&list);
}

void extract_getlost(const char* input_path, const char* output_dir) {
    if (!is_valid_archive_extension(input_path)) {
        fprintf(stderr, "[-] Invalid archive extension. Must be .GETLOST, .GETLOSTZ, or .GETLOST.Z\n");
        return;
    }

    printf("[+] Extracting %s -> %s\n", input_path, output_dir);

    FileList* entries = parse_archive(input_path);
    if (!entries) return;

    mkdir_recursive(output_dir);

    for (size_t i = 0; i < entries->count; i++) {
        char out_path[1024];
        snprintf(out_path, sizeof(out_path), "%s%c%s", output_dir, PATH_SEP, entries->entries[i].path);

        char* last_sep = strrchr(out_path, PATH_SEP);
        if (last_sep) {
            *last_sep = 0;
            mkdir_recursive(out_path);
            *last_sep = PATH_SEP;
        }

        FILE* f = fopen(out_path, "wb");
        if (f) {
            fwrite(entries->entries[i].data, 1, entries->entries[i].size, f);
            fclose(f);
            printf("[+] Extracted: %s (%zu bytes)\n", entries->entries[i].path, entries->entries[i].size);
        }
    }

    printf("\n[+] Extracted %zu files to %s\n", entries->count, output_dir);
    filelist_free(entries);
    free(entries);
}

#ifdef _WIN32
void execute_with_disk(const char* archive_path, const char* extensions) {
    if (!is_valid_archive_extension(archive_path)) {
        fprintf(stderr, "[-] Invalid archive extension. Must be .GETLOST, .GETLOSTZ, or .GETLOST.Z\n");
        return;
    }

    printf("[*] Executing with disk extraction (extensions: %s)\n", extensions);

    FileList* entries = parse_archive(archive_path);
    if (!entries) return;

    if (entries->count == 0) {
        fprintf(stderr, "[-] Archive is empty\n");
        filelist_free(entries);
        free(entries);
        return;
    }

    FileEntry* exec_entry = NULL;
    for (size_t i = 0; i < entries->count; i++) {
        const char* path = entries->entries[i].path;
        if (strchr(path, '/') == NULL && _stricmp(path, "xzpqexec.exe") == 0) {
            exec_entry = &entries->entries[i];
            printf("[+] Found xzpqexec.exe at root: %s (%zu bytes)\n", path, exec_entry->size);
            break;
        }
    }

    if (!exec_entry) {
        fprintf(stderr, "[-] xzpqexec.exe not found in the root directory of the archive\n");
        fprintf(stderr, "[-] Required: xzpqexec.exe at root (e.g., /xzpqexec.exe)\n");
        filelist_free(entries);
        free(entries);
        return;
    }

    char temp_dir[1024];
    char* localappdata = NULL;
    size_t len = 0;
    if (_dupenv_s(&localappdata, &len, "LOCALAPPDATA") == 0 && localappdata) {
        snprintf(temp_dir, sizeof(temp_dir), "%s\\Temp\\getlostz_temp", localappdata);
        free(localappdata);
    }
    else {
        strncpy(temp_dir, sizeof(temp_dir), "C:\\Windows\\Temp\\getlostz_temp", sizeof(temp_dir) - 1);
    }
    mkdir_recursive(temp_dir);
    printf("[+] Temp directory: %s\n", temp_dir);

    char* exts_copy = _strdup(extensions);
    if (!exts_copy) {
        fprintf(stderr, "[-] Memory allocation failed\n");
        filelist_free(entries);
        free(entries);
        return;
    }

    char* ext_tokens[100] = { 0 };
    int ext_count = 0;

    char* context = NULL;
    char* token = strtok_s(exts_copy, ",", &context);
    while (token && ext_count < 100) {
        while (*token == ' ') token++;
        if (*token) {
            ext_tokens[ext_count++] = token;
        }
        token = strtok_s(NULL, ",", &context);
    }

    char exec_path[1024] = { 0 };
    for (size_t i = 0; i < entries->count; i++) {
        int should_extract = 0;

        if (&entries->entries[i] == exec_entry) {
            should_extract = 1;
        }
        else {
            const char* ext = strrchr(entries->entries[i].path, '.');
            if (ext) {
                ext++;
                for (int j = 0; j < ext_count; j++) {
                    if (ext_tokens[j] && _stricmp(ext, ext_tokens[j]) == 0) {
                        should_extract = 1;
                        break;
                    }
                }
            }
        }

        if (should_extract) {
            char out_path[1024];
            snprintf(out_path, sizeof(out_path), "%s\\%s", temp_dir, entries->entries[i].path);

            char* last_sep = strrchr(out_path, '\\');
            if (last_sep) {
                *last_sep = 0;
                mkdir_recursive(out_path);
                *last_sep = '\\';
            }

            FILE* f = NULL;
            if (fopen_s(&f, out_path, "wb") == 0 && f) {
                fwrite(entries->entries[i].data, 1, entries->entries[i].size, f);
                fclose(f);
                printf("[+] Extracted: %s (%zu bytes)\n", entries->entries[i].path, entries->entries[i].size);

                if (&entries->entries[i] == exec_entry) {
                    strncpy(exec_path, sizeof(exec_path), out_path, sizeof(exec_path) - 1);
                }
            }
        }
    }

    free(exts_copy);

    if (exec_path[0]) {
        printf("[*] Launching: %s\n", exec_path);

        PROCESS_INFORMATION pi;
        STARTUPINFOA si;
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));

        if (CreateProcessA(exec_path, NULL, NULL, NULL, FALSE, 0, NULL, temp_dir, &si, &pi)) {
            printf("[+] Process started (PID: %lu)\n", pi.dwProcessId);
            WaitForSingleObject(pi.hProcess, INFINITE);

            DWORD exit_code;
            GetExitCodeProcess(pi.hProcess, &exit_code);
            printf("[+] Process exited with code %lu\n", exit_code);

            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
        else {
            fprintf(stderr, "[-] Failed to launch process (Error: %lu)\n", GetLastError());
        }
    }

    filelist_free(entries);
    free(entries);
}

void execute_in_memory(const char* archive_path) {
    if (!is_valid_archive_extension(archive_path)) {
        fprintf(stderr, "[-] Invalid archive extension. Must be .GETLOST, .GETLOSTZ, or .GETLOST.Z\n");
        return;
    }

    printf("[*] Executing in memory (no disk writing)\n");

    FileList* entries = parse_archive(archive_path);
    if (!entries) return;

    if (entries->count == 0) {
        fprintf(stderr, "[-] Archive is empty\n");
        filelist_free(entries);
        free(entries);
        return;
    }

    FileEntry* exec_entry = NULL;
    for (size_t i = 0; i < entries->count; i++) {
        if (strchr(entries->entries[i].path, '/') == NULL &&
            _stricmp(entries->entries[i].path, "xzpqexec.exe") == 0) {
            exec_entry = &entries->entries[i];
            printf("[+] Found xzpqexec.exe at root: %s (%zu bytes)\n", entries->entries[i].path, exec_entry->size);
            break;
        }
    }

    if (!exec_entry) {
        fprintf(stderr, "[-] xzpqexec.exe not found in root directory\n");
        filelist_free(entries);
        free(entries);
        return;
    }

    printf("[+] Executable size: %zu bytes\n", exec_entry->size);

    IMAGE_DOS_HEADER* dosHeader = (IMAGE_DOS_HEADER*)exec_entry->data;
    if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
        fprintf(stderr, "[-] Invalid DOS signature\n");
        filelist_free(entries);
        free(entries);
        return;
    }

    IMAGE_NT_HEADERS* ntHeaders = (IMAGE_NT_HEADERS*)(exec_entry->data + dosHeader->e_lfanew);
    if (ntHeaders->Signature != IMAGE_NT_SIGNATURE) {
        fprintf(stderr, "[-] Invalid NT signature\n");
        filelist_free(entries);
        free(entries);
        return;
    }

    printf("[+] Valid PE file detected\n");
    printf("[+] Entry point: 0x%X\n", ntHeaders->OptionalHeader.AddressOfEntryPoint);
    printf("[+] Image base: 0x%llX\n", (unsigned long long)ntHeaders->OptionalHeader.ImageBase);

    SIZE_T imageSize = ntHeaders->OptionalHeader.SizeOfImage;
    LPVOID imageBase = NULL;

    imageBase = VirtualAlloc(
        (LPVOID)(ULONG_PTR)ntHeaders->OptionalHeader.ImageBase,
        imageSize,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE
    );

    if (!imageBase) {
        imageBase = VirtualAlloc(
            NULL,
            imageSize,
            MEM_COMMIT | MEM_RESERVE,
            PAGE_EXECUTE_READWRITE
        );
    }

    if (!imageBase) {
        fprintf(stderr, "[-] Failed to allocate memory (Error: %lu)\n", GetLastError());
        filelist_free(entries);
        free(entries);
        return;
    }

    printf("[+] Allocated memory at 0x%p\n", imageBase);

    DWORD_PTR delta = (DWORD_PTR)imageBase - ntHeaders->OptionalHeader.ImageBase;
    printf("[*] Delta: 0x%llx\n", (unsigned long long)delta);

    ZeroMemory(imageBase, imageSize);

    memcpy(imageBase, exec_entry->data, ntHeaders->OptionalHeader.SizeOfHeaders);

    IMAGE_SECTION_HEADER* section = IMAGE_FIRST_SECTION(ntHeaders);
    for (WORD i = 0; i < ntHeaders->FileHeader.NumberOfSections; i++, section++) {
        if (section->SizeOfRawData > 0) {
            printf("[*] Copying section: %.8s at 0x%X (size: 0x%X)\n",
                section->Name, section->VirtualAddress, section->SizeOfRawData);
            memcpy(
                (char*)imageBase + section->VirtualAddress,
                exec_entry->data + section->PointerToRawData,
                section->SizeOfRawData
            );
        }
    }

    if (delta != 0) {
        printf("[*] Applying relocations...\n");
        IMAGE_DATA_DIRECTORY relocDir =
            ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];

        if (relocDir.Size > 0) {
            IMAGE_BASE_RELOCATION* reloc =
                (IMAGE_BASE_RELOCATION*)((char*)imageBase + relocDir.VirtualAddress);

            DWORD relocOffset = 0;

            while (relocOffset < relocDir.Size && reloc->VirtualAddress != 0) {
                DWORD numEntries = (reloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
                WORD* relocEntries = (WORD*)((char*)reloc + sizeof(IMAGE_BASE_RELOCATION));

                for (DWORD j = 0; j < numEntries; j++) {
                    DWORD type = relocEntries[j] >> 12;
                    DWORD offset = relocEntries[j] & 0xFFF;

                    if (type == IMAGE_REL_BASED_HIGHLOW) {
                        DWORD* patchAddr = (DWORD*)(
                            (char*)imageBase + reloc->VirtualAddress + offset
                            );
                        *patchAddr += (DWORD)delta;
                    }
                    else if (type == IMAGE_REL_BASED_DIR64) {
                        ULONGLONG* patchAddr = (ULONGLONG*)(
                            (char*)imageBase + reloc->VirtualAddress + offset
                            );
                        *patchAddr += delta;
                    }
                }

                relocOffset += reloc->SizeOfBlock;
                reloc = (IMAGE_BASE_RELOCATION*)((char*)reloc + reloc->SizeOfBlock);
            }
        }
    }

    printf("[*] Resolving imports...\n");
    IMAGE_DATA_DIRECTORY importDir =
        ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];

    if (importDir.Size > 0) {
        IMAGE_IMPORT_DESCRIPTOR* importDesc =
            (IMAGE_IMPORT_DESCRIPTOR*)((char*)imageBase + importDir.VirtualAddress);

        while (importDesc->Name != 0) {
            char* dllName = (char*)imageBase + importDesc->Name;
            HMODULE hDll = LoadLibraryA(dllName);

            if (hDll) {
                IMAGE_THUNK_DATA* thunk =
                    (IMAGE_THUNK_DATA*)((char*)imageBase + importDesc->FirstThunk);
                IMAGE_THUNK_DATA* originalThunk = importDesc->OriginalFirstThunk ?
                    (IMAGE_THUNK_DATA*)((char*)imageBase + importDesc->OriginalFirstThunk) : thunk;

                while (originalThunk->u1.AddressOfData != 0) {
                    FARPROC funcAddr = NULL;

                    if (originalThunk->u1.Ordinal & IMAGE_ORDINAL_FLAG) {
                        funcAddr = GetProcAddress(hDll,
                            (LPCSTR)(ULONG_PTR)(originalThunk->u1.Ordinal & 0xFFFF));
                    }
                    else {
                        IMAGE_IMPORT_BY_NAME* importByName =
                            (IMAGE_IMPORT_BY_NAME*)((char*)imageBase + originalThunk->u1.AddressOfData);
                        funcAddr = GetProcAddress(hDll, importByName->Name);

                        if (!funcAddr) {
                            printf("[!] Failed to resolve import: %s\n", importByName->Name);
                        }
                    }

                    if (funcAddr) {
                        thunk->u1.Function = (DWORD_PTR)funcAddr;
                    }

                    originalThunk++;
                    thunk++;
                }
            }
            else {
                printf("[!] Failed to load DLL: %s\n", dllName);
            }

            importDesc++;
        }
    }

    IMAGE_DATA_DIRECTORY tlsDir =
        ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS];

    if (tlsDir.Size > 0) {
        printf("[*] Processing TLS callbacks...\n");
        IMAGE_TLS_DIRECTORY* tls = (IMAGE_TLS_DIRECTORY*)((char*)imageBase + tlsDir.VirtualAddress);
        PIMAGE_TLS_CALLBACK* callback = (PIMAGE_TLS_CALLBACK*)tls->AddressOfCallBacks;

        if (callback) {
            while (*callback) {
                printf("[*] Calling TLS callback at 0x%p\n", *callback);
                (*callback)((LPVOID)imageBase, DLL_PROCESS_ATTACH, NULL);
                callback++;
            }
        }
    }

    printf("[*] Setting page protections...\n");
    section = IMAGE_FIRST_SECTION(ntHeaders);
    for (WORD i = 0; i < ntHeaders->FileHeader.NumberOfSections; i++, section++) {
        DWORD protect = PAGE_READWRITE;
        DWORD characteristics = section->Characteristics;

        if (characteristics & IMAGE_SCN_MEM_EXECUTE) {
            if (characteristics & IMAGE_SCN_MEM_WRITE) protect = PAGE_EXECUTE_READWRITE;
            else if (characteristics & IMAGE_SCN_MEM_READ) protect = PAGE_EXECUTE_READ;
            else protect = PAGE_EXECUTE;
        }
        else {
            if (characteristics & IMAGE_SCN_MEM_WRITE) protect = PAGE_READWRITE;
            else if (characteristics & IMAGE_SCN_MEM_READ) protect = PAGE_READONLY;
            else protect = PAGE_NOACCESS;
        }

        DWORD oldProtect;
        SIZE_T protectSize = section->Misc.VirtualSize ? section->Misc.VirtualSize : section->SizeOfRawData;

        if (protectSize > 0) {
            VirtualProtect(
                (char*)imageBase + section->VirtualAddress,
                protectSize,
                protect,
                &oldProtect
            );
        }
    }

    FlushInstructionCache(GetCurrentProcess(), imageBase, imageSize);

    if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
        AllocConsole();
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
        freopen("CONIN$", "r", stdin);
    }

#if defined(_M_X64) || defined(__amd64__)
    void** peb = (void**)__readgsqword(0x60);
    peb[2] = imageBase;
#elif defined(_M_IX86) || defined(__i386__)
    void** peb = (void**)__readfsdword(0x30);
    peb[2] = imageBase;
#endif

    printf("[*] Executing entry point at 0x%p...\n", (char*)imageBase + ntHeaders->OptionalHeader.AddressOfEntryPoint);
    printf("[*] Output should appear below:\n");
    printf("========================================\n");
    fflush(stdout);

    DWORD entryPoint = ntHeaders->OptionalHeader.AddressOfEntryPoint;
    void* entryFunc = (char*)imageBase + entryPoint;

    HANDLE hThread = CreateThread(
        NULL,
        0,
        (LPTHREAD_START_ROUTINE)entryFunc,
        NULL,
        0,
        NULL
    );

    if (hThread) {
        WaitForSingleObject(hThread, INFINITE);

        DWORD exitCode = 0;
        GetExitCodeThread(hThread, &exitCode);
        printf("========================================\n");
        printf("[+] Execution completed with exit code: %lu\n", exitCode);
        CloseHandle(hThread);

        FreeConsole();
    }
    else {
        printf("[!] CreateThread failed, trying direct call...\n");
        DWORD result = ((DWORD(*)(void))entryFunc)();
        printf("========================================\n");
        printf("[+] Direct call returned: %lu\n", result);
    }

    filelist_free(entries);
    free(entries);
}
#else
void execute_with_disk(const char* archive_path, const char* extensions) {
    fprintf(stderr, "[-] execute -w is only supported on Windows.\n");
    (void)archive_path; (void)extensions;
}

void execute_in_memory(const char* archive_path) {
    fprintf(stderr, "[-] execute -m is only supported on Windows.\n");
    (void)archive_path;
}
#endif

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("getlostz - Archive tool for .GETLOST files\n\n");
        printf("Usage:\n");
        printf("  getlostz pack <folder> <output.GETLOST>\n");
        printf("  getlostz extract <input.GETLOST> <output_folder>\n");
        printf("  getlostz execute -w <ext1,ext2,...> <archive.GETLOST>\n");
        printf("  getlostz execute -m <archive.GETLOST>\n");
        printf("\nExamples:\n");
        printf("  getlostz pack ./documents archive.GETLOST\n");
        printf("  getlostz extract archive.GETLOST ./restored\n");
        printf("  getlostz execute -w dll,pdb example_archive.GETLOST\n");
        printf("  getlostz execute -m example_archive.GETLOST\n");
        return 1;
    }

    if (strcmp(argv[1], "pack") == 0) {
        create_getlost(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "extract") == 0) {
        extract_getlost(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "execute") == 0) {
        if (strcmp(argv[2], "-w") == 0) {
            if (argc < 5) {
                fprintf(stderr, "[-] Missing extensions or archive path\n");
                return 1;
            }
            execute_with_disk(argv[4], argv[3]);
        }
        else if (strcmp(argv[2], "-m") == 0) {
            if (argc < 4) {
                fprintf(stderr, "[-] Missing archive path\n");
                return 1;
            }
            execute_in_memory(argv[3]);
        }
        else {
            fprintf(stderr, "[-] Invalid execute flag. Use -w (write to disk) or -m (memory)\n");
            return 1;
        }
    }
    else {
        fprintf(stderr, "[-] Unknown command. Use 'pack', 'extract', or 'execute'\n");
        return 1;
    }

    return 0;
}
