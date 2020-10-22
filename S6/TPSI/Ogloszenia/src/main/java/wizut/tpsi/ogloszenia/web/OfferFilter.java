/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package wizut.tpsi.ogloszenia.web;

/**
 *
 * @author Student
 */
public class OfferFilter {
    private Integer manufacturerId;
    private Integer modelId;

    public Integer getManufacturerId() {
        return manufacturerId;
    }

    public Integer getModelId() {
        return modelId;
    }

    public void setManufacturerId(Integer manufacturerId) {
        this.manufacturerId = manufacturerId;
    }

    public void setModelId(Integer modelId) {
        this.modelId = modelId;
    }
    
}
