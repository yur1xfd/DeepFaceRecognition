import os
import pytest

input_raw_dir = "input_raw"
input_dir = "input"
output_raw_dir = "output_raw"
output_dir = "output"

def test_preprocessing() -> None:
    input_files = ([f[:-4] for f in os.listdir(input_raw_dir) if f.endswith('.png')] +
                   [f for f in os.listdir(input_raw_dir) if f.endswith('.jpg')])
    processed_files = ([f[:-4] for f in os.listdir(input_dir) if f.endswith('.png')] +
                   [f for f in os.listdir(input_dir) if f.endswith('.jpg')])
    
    for file_pattern in input_files:
        assert file_pattern in processed_files

def test_processing() -> None:
    processed_files = ([f for f in os.listdir(output_raw_dir)])
    assert "bounding_boxes.json" in processed_files

def test_postprocessing() -> None:
    input_files = (["output_" + f for f in os.listdir(input_dir) if f.endswith('.jpg')] +
                   ["output_" + f for f in os.listdir(input_dir) if f.endswith('.png')])
    output_files = ([f for f in os.listdir(output_dir) if f.endswith('.jpg')] +
                   [f for f in os.listdir(output_dir) if f.endswith('.png')])
    
    for file_pattern in input_files:
        assert file_pattern in output_files
